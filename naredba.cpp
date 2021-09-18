#include "naredba.hpp"

extern map<string, int> tablica;

void IspisS::izvrsi() const {
	cout << _s << endl;
}

void IspisE::izvrsi() const {
	cout << _i->vrednost() << endl;
}

IspisE::~IspisE() {
	delete _i;
}

void Blok::izvrsi() const {
	for(unsigned i=0; i < _v.size(); i++) {
		_v[i]->izvrsi();
	}
}

Blok::~Blok() {
	for(unsigned i=0; i < _v.size(); i++) {
		delete _v[i];
	}
}

NaredbaDodele::~NaredbaDodele() {
	delete _i;
}

void NaredbaDodele::izvrsi() const {
	tablica[_s] = _i->vrednost();
}

void Unesi::izvrsi() const {
	int tmp;
	cin >> tmp;
	tablica[_s] = tmp;
}

AkoJeOndaInace::~AkoJeOndaInace() {
	delete _i;
	delete _n1;
	delete _n2;
}

void AkoJeOndaInace::izvrsi() const {
	if(_i->vrednost()) {
		_n1->izvrsi();
	} else {
		_n2->izvrsi();
	}
}

AkoJeOnda::~AkoJeOnda() {
	delete _i;
	delete _n1;
}

void AkoJeOnda::izvrsi() const {
	if(_i->vrednost())
		_n1->izvrsi();
}

DokJe::~DokJe() {
	delete _i;
	delete _n;
}

void DokJe::izvrsi() const {
	while(_i->vrednost())
		_n->izvrsi();
}