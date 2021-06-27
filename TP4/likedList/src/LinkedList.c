#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this=(LinkedList*) malloc (sizeof(LinkedList));

    if(this!=NULL)
    {
    	this->size=0;//TAMAÑO EN 0
    	this->pFirstNode=NULL;//FINAL DE LA LISTA NULL
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;

	if(this!=NULL)
	{
		returnAux=this->size;//DEVUELVE EL TAMAÑO
	}
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxiliar = NULL;
	int i;

	if(this!=NULL && nodeIndex > -1 && nodeIndex < ll_len(this))//VERIFICO QUE LA LISTA NO SEA NULL Y INDEX NO SEA MENOR A CERO
	{
	   auxiliar = this->pFirstNode;//ASIGNO EL PRIMER NODO
	   if(auxiliar != NULL)
	   {
		  if(nodeIndex != 0)
	      {
			  for(i=0; i < nodeIndex;i++)//RECORRIDO HASTA LA CANTIDAD QUE INGRESA
			  {
				  auxiliar = auxiliar->pNextNode;//IGUALA HASTA LLEGAR AL ULTIMO
			  }
	       }
	    }
	 }
 return auxiliar;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    Node *pNewNode = (Node*) malloc(sizeof(Node));
    int returnAux= -1;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) && pNewNode !=NULL)
    {
    	pNewNode->pElement= pElement;
    	pNewNode->pNextNode=NULL;

    	if(nodeIndex == 0)//VERIFICO SI ES EL PRIMER ELEMENTO DE LA LISTA
    	{
    		pNewNode->pNextNode=this->pFirstNode;
    		this->pFirstNode=pNewNode;
    	}
    	else
    	{
    		pNewNode->pNextNode= getNode(this, nodeIndex);
    		getNode(this, nodeIndex - 1)->pNextNode=pNewNode;
    	}
    	this->size++;
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int length;

    length=ll_len(this);

    if(this!=NULL)
    {
    	addNode(this,length,pElement);

    	returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int length;
    Node* NodeAux;

    length=ll_len(this);
    if(this != NULL && index >= 0 && index < length && length > 0)
    {
       NodeAux = getNode(this,index);
       returnAux = NodeAux->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* NodeAux;
    int length;

    length=ll_len(this);
    if(this != NULL && index >= 0 && index < length && length > 0)
    {
    	NodeAux=getNode(this,index);
    	NodeAux->pElement=pElement;
    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux=-1;
    int length;
    Node* NodeAux;
    Node* Next;
    Node* Prev;

    length=ll_len(this);

    if(this != NULL && index >= 0 && index < length && length > 0)
    {
    	if(index==0)
    	{
			NodeAux=getNode(this,index);
			this->pFirstNode = NodeAux->pNextNode;
			free(NodeAux);
			this->size--;
			returnAux=0;
    	}
    	else
    	{
    		if(index==1)
    		{
    			NodeAux = getNode(this,index);
    			Prev = getNode(this,index-1);
    			Next = getNode(this,index+1);
    			Prev->pNextNode = Next;
    			free(NodeAux);
    			this->size--;
    			returnAux = 0;
    		}
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int length;

    length=ll_len(this);

    if(this!=NULL)
    {
    	for(i=0;i<length;i++)
    	{
    		ll_remove(this,i);
    	}
    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int length;
    Node* aux=NULL;

    length= ll_len(this);

    if(this!=NULL)
    {
    	for(i=0;i<length;i++)
    	{
    		aux=getNode(this,i);
    		if(aux->pElement==pElement)
    		{
    			returnAux=i;
    			break;
    		}
    	}
    }
 return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int length;


    if(this!=NULL)
    {
    	length=ll_len(this);

    	if(length>0)
    	{
    		returnAux=0;
    	}
    	else
    	{
    		returnAux=1;
    	}

    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int length;

    length=ll_len(this);

    if(this!=NULL && index>=0 && index <=length)
    {
    	addNode(this,index,pElement);
    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int length;
    void* NodeAux;

    length=ll_len(this);

    if(this!=NULL && index>=0 && index <=length)
    {
    	NodeAux=ll_get(this,index);
    	ll_remove(this,index);
    	returnAux=NodeAux;
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int length;
    int bandera=0;
    Node* aux;

    length=ll_len(this);

    if(this!=NULL)
    {
    	for(i=0;i<length;i++)
    	{
    		aux=getNode(this,i);
    		if(aux->pElement==pElement)
    		{
    			returnAux=1;
    			bandera=1;
    		}
    	}
    	if(bandera==0)
    	{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int accountant=0;
    Node* Aux;

    if(this!=NULL && this2 != NULL)
    {
    	for(i=0;i<this2->size;i++)
    	{
    		Aux=ll_get(this2,i);

    		if(ll_contains(this,Aux))
    		{
    			accountant++;
    		}
    	}
    	if(accountant==this2->size)
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* Aux=NULL;
    int i;

    if(this!=NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
    	cloneArray= ll_newLinkedList();
    	if(cloneArray!=NULL)
    	{
    		for(i=0;i<to;i++)
    		{
    			Aux=getNode(this,i);
    			addNode(cloneArray,i,Aux->pElement);
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
    	cloneArray=ll_subList(this,0,ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux=-1;
	int i;
	void* pElement1;
	void* pElement2;
	int bandera;
	int length;

	if(this!=NULL && order>=0 && pFunc != NULL)
	{
		length=ll_len(this);
		do
		{
			bandera=0;
			for(i=0;i<length-1;i++)
			{
				pElement1=ll_get(this,i);
				pElement2=ll_get(this,i+1);
				if( ((pFunc(pElement1,pElement2)<0)&& order==0) ||
					((pFunc(pElement1,pElement2)>0)&& order==1) )
				{
					bandera=1;
					ll_set(this,i,pElement2);
					ll_set(this,i + 1,pElement1);
				}
			}
		}while(bandera==1);
		returnAux=0;
	}

    return returnAux;

}

