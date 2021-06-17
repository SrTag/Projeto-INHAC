#pragma once

using namespace std;

template <class T>
class NoT
{
public:
	//Metodos
	NoT();
	~NoT();

	void defineProximo(NoT* prox_no);
	void defineInfo(T pessoa);
	void defineAnterior(NoT* ant_no);

	T obtemInfo();

	NoT<T> *obtemProximo();
	NoT<T> *obtemAnterior();


private:
	//Atributos
	T info;
	NoT* prox;
	NoT* anterior;
};

template<class T>
inline NoT<T>::NoT()
{
	prox = nullptr;
	anterior = nullptr;
}

template<class T>
inline NoT<T>::~NoT()
{
}

template<class T>
inline void NoT<T>::defineProximo(NoT* prox_no)
{
	prox = prox_no;
}

template<class T>
inline void NoT<T>::defineInfo(T elemento)
{
	info = elemento;
}

template<class T>
inline void NoT<T>::defineAnterior(NoT* ant_no)
{
	anterior = ant_no;
}

template<class T>
inline T NoT<T>::obtemInfo()
{
	return this->info;
}

template<class T>
inline NoT<T>* NoT<T>::obtemProximo()
{
	return this->prox;
}

template<class T>
inline NoT<T>* NoT<T>::obtemAnterior()
{
	return this->anterior;
}
