

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Egg {
protected:
	string size;
	string flavor;

public:
	Egg(string s, string f) {
		size = s;
		flavor = f;
	}
	virtual void eat_egg() = 0;
	

	string sizegetter() {
		return size;
	}

	string flavorgetter(){
		return flavor;
	}

};


class cow_egg : public Egg {
public:
	cow_egg() : Egg("huge", "bittery") {}


	void eat_egg() {
		cout << "you just ate a " << size << " cow egg, it taste kinda " << flavor << " tbh" <<  endl;

	}

};


class Elephant_egg : public Egg {
public:
	Elephant_egg() : Egg("humungeous", "disgusting") {}


	void eat_egg() {
		cout << "you just ate a " << size << " Elephant egg, it taste kinda " << flavor << " tbh" << endl;

	}

};




class bad_egg {
public:
	string comment() {
		return "There was a rotten Egg!";
	}
};

class rotten_egg : public Egg {
public:
	rotten_egg() : Egg("small", "awful") {}


	void eat_egg() {
		throw bad_egg();

	}

};

//n egg should also have a purely virtual function called eat_egg, which is intended to print a textual description of what eating the egg is like.




class Carton {
protected:
	vector<Egg*> eggs;

public:
	void insertEgg(Egg* e) {
		if (eggs.size() < 12) {
			eggs.push_back(e);
		}
		else {
			cout << "This carton is full" << endl;
		}
	}

	void eatEgg() {
		if (eggs.size() == 0) {
			cout << "Carton is empty" << endl;
			return;

		}
		Egg* e = eggs[eggs.size() - 1];
		eggs.pop_back();

		try {
			e->eat_egg();
		}
		catch (bad_egg bad) {
			cout << bad.comment() << endl;
		}
	}



};









int main()
{
	cow_egg egg1 = cow_egg();
	rotten_egg egg2 = rotten_egg();
	Elephant_egg egg3 = Elephant_egg();
	Carton c;
	c.insertEgg(&egg1);
	c.insertEgg(&egg2);
	c.insertEgg(&egg3);

	c.eatEgg();
	c.eatEgg();

	c.eatEgg();



}
