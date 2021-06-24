#pragma once
#include <iostream>
#include "NoT.h"
#include "libUnicornio.h"

using namespace std;
template <class T>

class Fila
{
private:
	NoT<T>* primeiro;
	NoT<T>* ultimo;
	int qtElementos;
	bool vazia();
	Sprite sprite[15];
public:
	Fila();
	~Fila();
	void enfileirar(T dado);
	void desinfileirar();
	T primeiroDaFila();
	T ultimoDaFila();
	void mostrarFila();
	int tamanhoFila();
};

template<class T>
inline bool Fila<T>::vazia()
{
	if (primeiro == nullptr)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template<class T>
inline Fila<T>::Fila()
{
	primeiro = nullptr;
	ultimo = nullptr;
	qtElementos = 0;
}

template<class T>
inline Fila<T>::~Fila()
{
}

template<class T>
inline void Fila<T>::enfileirar(T dado)
{
	NoT<T>* novo_nodo = new NoT<T>();
	novo_nodo->defineInfo(dado);

	if (vazia())
	{

		primeiro = novo_nodo;
		ultimo = novo_nodo;
	}
	else
	{

		ultimo->defineProximo(novo_nodo);
		ultimo = novo_nodo;
	}
	qtElementos++;
}

template<class T>
inline void Fila<T>::desinfileirar()
{
	if (!vazia())
	{
		if (qtElementos == 1)
		{
			delete primeiro;
			primeiro = nullptr;
			ultimo = nullptr;
			
		}
		else
		{
			NoT<T>* aux;
			aux = primeiro; 
			primeiro = primeiro->obtemProximo(); 
			delete aux; 
		}
		qtElementos--;
	}
}

template<class T>
inline T Fila<T>::primeiroDaFila()
{
	if (!vazia())
	{
		T elemento;

		elemento = primeiro->obtemInfo();
		return elemento;
	}
	return NULL;
}

template<class T>
inline T Fila<T>::ultimoDaFila()
{
	if (!vazia())
	{
		T* elemento;

		elemento = ultimo->obtemInfo();
		return elemento;
	}
	return nullptr;
}

template<class T>
inline void Fila<T>::mostrarFila()
{
	int pos=0;
	
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
			uniIniciarFrame();
			sprite[0].desenhar()

			uniTerminarFrame();
	}
	
}

template<class T>
inline int Fila<T>::tamanhoFila()
{
	return qtElementos;
}
