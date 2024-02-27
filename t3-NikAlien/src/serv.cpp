//
// Created by Carp Nicoleta on 25.05.2023.
//

#include "serv.h"

std::vector<Document> Service::getDocList() const {
    std::vector<Document> list = repo->getAll();

    for(int i = 0; i < list.size() - 1; i++)
    {
        for(int j = 0; j < list.size() - 1; j++)
            if(list[j].getName() > list[j + 1].getName())
                std::swap(list[j], list[j + 1]);
    }
    return list;
}

std::vector<Document> Service::filterDocList(std::string fil) const {
    std::vector<Document> list = this->getDocList();
    std::vector<Document> result;

    for(const auto & i : list)
    {
        if(i.getName().find(fil) != std::string::npos || i.getKeywords().find(fil) != std::string::npos)
            result.push_back(i);
    }
    return result;
}

Document Service::bestMatching(std::string name) {
    std::vector<Document> list = repo->getAll();
    std::vector<Document> result;
    int index;
    double max = 0;

    for(const auto & i : list)
    {
        if(i.getName().find(name) != std::string::npos)
            result.push_back(i);
    }

    if(result.size() == 0)
    {
        return Document("", "", "");
    }

    for(int i = 0; i < result.size(); i++)
    {
        if(max < name.size() / result[i].getName().size())
        {
            index = i;
            max = name.size() / result[i].getName().size();
        }
    }

    return result[index];
}
