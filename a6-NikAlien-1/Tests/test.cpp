#include "test.h"
#include "Domain/Dog.h"
#include "Repository/Repo.h"
#include "Service/Service.h"
#include <assert.h>
#include <vector>

using namespace std;

void testAdd()
{
    std::vector<Dog> arr;
    Repository repo (&arr);
    Service serv(&repo);

    assert(serv.addDogToList("husky", "Akira", 6, "photo1") == 1);
    assert(serv.addDogToList("chihuahua", "King", 3, "photo2") == 1);
    assert(serv.addDogToList("husky", "Billy", 5, "photo3") == 1);
    assert(serv.addDogToList("laika", "Billy", 4, "photo4") == 0);
}

void testRemove()
{
    std::vector<Dog> arr;
    Repository repo (&arr);
    Service serv(&repo);

    serv.init();

    assert(serv.removeDogFromList("King") == 1);
    assert(serv.removeDogFromList("King") == 0);
}

void testUpdate()
{
    std::vector<Dog> arr;
    Repository repo (&arr);
    Service serv(&repo);
    Dog d;
    d.setAge(7);

    serv.init();
    assert(arr[1].getAge() == 3);
    assert(arr[2].getPhotograph() == "https://www.insidedogsworld.com/wp-content/uploads/2016/12/husky10.jpg");

    serv.updateDogAge("King", 7);
    assert(arr[1].getAge() == d.getAge());

    serv.updateDogPhoto("Billy", "ph");
    assert(arr[2].getPhotograph() == "ph");

    assert(serv.updateDogPhoto("jj", "ph") == 0);
    assert(serv.updateDogAge("jj", 8) == 0);
}

void testGetList()
{
    std::vector<Dog> arr;
    Repository repo (&arr);
    Service serv(&repo);

    serv.init();

    vector<Dog> copy = *(serv.getDogList());
    assert(copy.size() == arr.size());

    assert(copy[0].getName() == arr[0].getName());
    assert(copy[0].getBreed() == arr[0].getBreed());

    assert(copy[1].getName() == arr[1].getName());
    assert(copy[1].getBreed() == arr[1].getBreed());

    assert(copy[2].getName() == arr[2].getName());
    assert(copy[2].getBreed() == arr[2].getBreed());
}

void testValidations()
{
    std::vector<Dog> arr;
    Repository repo (&arr);
    Service serv(&repo);

    assert(serv.breedValid("corgi"));
    assert(!serv.breedValid("jgj"));

    assert(!serv.ageValid("lkhjghfgd"));
    assert(!serv.ageValid("20hkjghy"));
    assert(!serv.ageValid("fgh4hhj"));
    assert(!serv.ageValid("-9"));
    assert(!serv.ageValid("34"));
    assert(serv.ageValid("6"));

    string name = "HILL";
    serv.makeNameValid(name);
    assert(name == "Hill");

    name = "hill";
    serv.makeNameValid(name);
    assert(name == "Hill");

    name = "Hill";
    serv.makeNameValid(name);
    assert(name == "Hill");

    name = "hIlL";
    serv.makeNameValid(name);
    assert(name == "Hill");

    name = "HiLl";
    serv.makeNameValid(name);
    assert(name == "Hill");

    string link = "photo";
    serv.makeLinkValid(link);
    assert(link == "https://photo");

    link = "https://photo1";
    serv.makeLinkValid(link);
    assert(link == "https://photo1");

}

void testUserMode()
{
    std::vector<Dog> arr;
    Repository repo (&arr);
    Service serv(&repo);
    serv.init();

    vector<Dog*> list = serv.createListUser("", -1);
    assert(list.size() == arr.size());
    assert(list.operator[](3)->getName() == arr[3].getName());
    assert(list.operator[](5)->getBreed() == arr[5].getBreed());

    vector<Dog*> list2 = serv.createListUser("husky", 10);
    assert(list2.size() == 2);
    assert(list2.operator[](1)->getName() == "Billy");

    vector<Dog*> list3 = serv.createListUser("husky", 5);
    assert(list3.size() == 1);
    assert(list3.operator[](0)->getName() == "Billy");

    assert(serv.getAdopted() == 0);
    serv.setAdopted(56);
    assert(serv.getAdopted() == 56);

    Dog d = *(list3.operator[](0));
    assert(!d.getFlag());
    d.setFlag(true);
    assert(d.getFlag());

}

void testAll()
{
    testAdd();
    testRemove();
    testUpdate();
    testGetList();
    testValidations();
    testUserMode();
}