#ifndef __NAREDBA_HPP__
#define __NAREDBA_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "izraz.hpp"
using namespace std;


class Naredba {
public:
	virtual ~Naredba() {
		
	}
	virtual void izvrsi() const = 0;
};

class IspisS : public Naredba {
public:
	IspisS(string s)
		:_s(s)
	{}
	void izvrsi() const;
private:
	string _s;
};

class IspisE : public Naredba {
public:
	IspisE(Izraz *i)
		:_i(i)
	{}
	~IspisE();
	void izvrsi() const;
private:
	Izraz *_i;
	IspisE(const IspisE&);
	IspisE operator=(const IspisE&);
};

class Blok : public Naredba {
public:
	Blok(vector<Naredba*> v)
		:_v(v)
	{}
	~Blok();
	void izvrsi() const;
private:
	vector<Naredba*> _v;
	Blok(const Blok&);
	Blok operator=(const Blok&);
};

class NaredbaDodele : public Naredba {
public:
	NaredbaDodele(string s, Izraz *i)
		:_s(s), _i(i)
	{}
	void izvrsi() const;
	~NaredbaDodele();
private:
	NaredbaDodele(const NaredbaDodele&);
	NaredbaDodele operator=(const NaredbaDodele&);
	string _s;
	Izraz* _i;
};

class Unesi : public Naredba {
public:
	Unesi(string s)
		:_s(s)
	{}
	void izvrsi() const;
private:
	string _s;
};

class AkoJeOndaInace : public Naredba {
public:
	AkoJeOndaInace(Izraz *i, Naredba *n1, Naredba *n2)
		:_i(i), _n1(n1), _n2(n2)
	{}
	void izvrsi() const;
	~AkoJeOndaInace();
private:
	AkoJeOndaInace(const AkoJeOndaInace&);
	AkoJeOndaInace operator=(const AkoJeOndaInace&);
	Izraz *_i;
	Naredba *_n1;
	Naredba *_n2;
};

class AkoJeOnda : public Naredba {
public:
	AkoJeOnda(Izraz *i, Naredba *n1)
		:_i(i), _n1(n1)
	{}
	void izvrsi() const;
	~AkoJeOnda();
private:
	AkoJeOnda(const AkoJeOnda&);
	AkoJeOnda operator=(const AkoJeOnda&);
	Izraz *_i;
	Naredba *_n1;
};

class DokJe : public Naredba {
public:
	DokJe(Izraz *i, Naredba *n)
		:_i(i), _n(n)
	{}
	void izvrsi() const;
	~DokJe();
private:
	DokJe(const DokJe&);
	DokJe operator=(const DokJe&);
	Izraz *_i;
	Naredba *_n;
};


#endif