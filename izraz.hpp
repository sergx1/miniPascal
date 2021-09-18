#ifndef __IZRAZ_HPP__
#define __IZRAZ_HPP__

#include <iostream>
#include <string>
#include <map>
using  namespace std;

class Izraz {
public:
	virtual ~Izraz() {
		
	}
	virtual int vrednost() const = 0;
};

class Promenljiva : public Izraz {
public:
	Promenljiva(string ime)
		:_ime(ime)
	{}
	int vrednost() const;
private:
	string _ime;
};

class Konstanta : public Izraz {
public:
	Konstanta(int broj)
		:_broj(broj)
	{}
	int vrednost() const;
private:
	int _broj;
};

class BinOp : public Izraz {
public:
	BinOp(Izraz *i1, Izraz *i2)
		:_levi(i1), _desni(i2)
	{}
	~BinOp() {
		delete _levi;
		delete _desni;
	}

private:
	BinOp(const BinOp &b);
protected:
	Izraz* _levi;
	Izraz* _desni;
};

class Zbir : public BinOp {
public:
	Zbir(Izraz *i1, Izraz *i2)
		:BinOp(i1, i2)
	{}

	int vrednost() const;
};

class Razlika : public BinOp {
public:
	Razlika(Izraz *i1, Izraz *i2)
		:BinOp(i1, i2)
	{}

	int vrednost() const;
};

class Proizvod : public BinOp {
public:
	Proizvod(Izraz *i1, Izraz *i2)
		:BinOp(i1, i2)
	{}

	int vrednost() const;
};

class Kolicnik : public BinOp {
public:
	Kolicnik(Izraz *i1, Izraz *i2)
		:BinOp(i1, i2)
	{}

	int vrednost() const;
};

class Mod : public BinOp {
public:
	Mod(Izraz *i1, Izraz *i2)
		:BinOp(i1, i2)
	{}

	int vrednost() const;
};

class Manje : public BinOp {
public:
	Manje(Izraz *i1, Izraz *i2)
		:BinOp(i1, i2)
	{}

	int vrednost() const;
};

class Vece : public BinOp {
public:
	Vece(Izraz *i1, Izraz *i2)
		:BinOp(i1, i2)
	{}

	int vrednost() const;
};


#endif