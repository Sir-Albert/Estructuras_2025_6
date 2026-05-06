#include "HashQ.h"


int fn_hashQ(HashQTable hashtable,int key)
{
	return key % hashtable.len;
}

int fn_rehashQ(HashQTable hashtable,int index,int k)
{
	return (index+k*k) % hashtable.len;	
}

int fn_insertKey(HashQTable *hashtable,void *data)
{
	int index,n_index,k=0,key;
	key = hashtable->folding(data);
	index = fn_hashQ(*hashtable,key);
	
	if( hashtable->table[index] == NULL)
	{
		hashtable->table[index] = data;
		hashtable->cant++;
		printf("\n K: %d",k);
		return 1;
	}
	else
	{
		k = 1;
		n_index = fn_rehashQ(*hashtable,index,k);
		
		while(hashtable->table[n_index] != NULL)
		{			
			k += 1;
			n_index = fn_rehashQ(*hashtable,index,k);
			
		}		
		hashtable->table[n_index] = data;
		hashtable->cant++;
		printf("\n K: %d",k);
		return 1;		
	}	
}


void* fn_searchKey(HashQTable *hashtable,void *data)
{	
	int index,n_index,k=0,key;
	key = hashtable->folding(data);
	index = fn_hashQ(*hashtable,key);
	
	if(hashtable->table[index]==NULL)
		return NULL;
	void *dataTable = hashtable->table[index];
	
	if( hashtable->comparar(dataTable,data) == 0 )
	{	
		printf("\n K: %d",k);
		return dataTable;	
	}
	
	else
	{
		k = 1;
		n_index = fn_rehashQ(*hashtable,index,k);
		dataTable = hashtable->table[n_index];
		
		while(dataTable != NULL )
		{
			if( hashtable->comparar(dataTable,data) == 0)
			{
				printf("\n K: %d",k);
				return dataTable;	
			}			
			k += 1;
			n_index = fn_rehashQ(*hashtable,index,k);
			dataTable = hashtable->table[n_index];		
		}
		return NULL;
	}
	

}