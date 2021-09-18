#include "izraz.hpp"

extern void yyerror(string s);

extern map<string, int> tablica;

int Promenljiva::vrednost() const {
	return tablica[_ime];
}

int Konstanta::vrednost() const {
	return _broj;
}

int Zbir::vrednost() const {
	return _levi->vrednost() + _desni->vrednost();
}

int Razlika::vrednost() const {
	return _levi->vrednost() - _desni->vrednost();
}

int Proizvod::vrednost() const {
	return _levi->vrednost() * _desni->vrednost();
}

int Kolicnik::vrednost() const {
	if(_desni->vrednost() == 0) {
		yyerror("Deljenje nulom nije dozvoljeno!");
	}
	return _levi->vrednost() / _desni->vrednost();
}

int Mod::vrednost() const {
	return _levi->vrednost() % _desni->vrednost();
}

int Manje::vrednost() const {
	return _levi->vrednost() < _desni->vrednost();
}

int Vece::vrednost() const {
	return _levi->vrednost() > _desni->vrednost();
}