//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//#define V 9

//int minDistance(int dist[], bool sptSet[]){
//
//	int min = INT_MAX, min_index;
//
//	for (int v = 0; v < V; v++)
//		if (sptSet[v] == false && dist[v] <= min)
//			min = dist[v], min_index = v;
//
//	return min_index;
//}

//void printSolution(int dist[]){
//	cout << "Vertex \t Distance from Source" << endl;
//	for (int i = 0; i < V; i++)
//		cout << i << " \t\t" << dist[i] << endl;
//}

//void dijkstra(int graph[V][V], int src){
//	int dist[V]; 
//
//	bool sptSet[V]; 
//
//	for (int i = 0; i < V; i++)
//		dist[i] = INT_MAX, sptSet[i] = false;
//
//	// Distance of source vertex from itself is always 0
//	dist[src] = 0;
//
//	// Find shortest path for all vertices
//	for (int count = 0; count < V - 1; count++) {
//		int u = minDistance(dist, sptSet);
//		sptSet[u] = true;
//		for (int v = 0; v < V; v++)
//			if (!sptSet[v] && graph[u][v]
//				&& dist[u] != INT_MAX
//				&& dist[u] + graph[u][v] < dist[v])
//				dist[v] = dist[u] + graph[u][v];
//	}
//
//	printSolution(dist);
//}

//int main(){
//
//	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
//						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
//						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
//						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
//						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
//						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
//						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
//						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
//						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
//
//	dijkstra(graph, 0);
//
//	return 0;
//}
//
////size -> para arreglos y string


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <queue>

//using namespace System;
using namespace std;


#define Max 10005
#define Node pair<int,int>
#define INF 1<<30

struct cmp {
	bool operator ()(const Node& a, const Node& b) {
		return a.second > b.second;
	}
};

vector<Node>ady[Max];
int distancia[Max];
bool visitado[Max];
priority_queue<Node, vector<Node>, cmp >Q;

int v;
int previo[Max];//Para el camino

//Funcion de inicializacion
void init() {
	for (int i = 0; i <= v; i++) {
		distancia[i] = INF;//Inicializamos a toda la distancia con infinito
		visitado[i] = false;//Inicializamos a toda la vertices o nodos como visitado
		previo[i] = -1;//Inicializamos el previo vertice i con -1
	}
}

//Para minimizacion
void relajacion(int actual, int adyacente, int peso) {
	if (distancia[actual] + peso < distancia[adyacente]) {
		distancia[adyacente] = distancia[actual] + peso;
		previo[adyacente] = actual;// A su ves actualizamos el previo del vertice
		Q.push(Node(adyacente, distancia[adyacente]));//Agregamos adyacente a la cola de prioridad
	}
}

//Desde el camino corto del vertice inicial hasta el vertice final
void prinf(int destino) {
	if (previo[destino] != -1)
		cout<<previo[destino];
	cout << destino;//Termina la recursion imprimo los vertices recorrido
}

void dijkstra(int inicial) {
	init();//Inicializamos nuestros arreglos
	Q.push(Node(inicial, 0));
	distancia[inicial] = 0;
	int actual, adyacente, peso;
	while (!Q.empty()) {
		actual = Q.top().first;
		Q.pop();
		if (visitado[actual])continue;//
		visitado[actual] = true;//Marco como visitado el vertice actual

		for (int i = 0; i < ady[actual].size(); i++) {//reviso sus adyacentes del vertice actual 
			adyacente = ady[actual][i].first;
			peso = ady[actual][i].second;
			if (!visitado[adyacente]) {//Si el vertice adyacente no fue visitado
				relajacion(actual, adyacente, peso);//Realizamos el paso de la relajacion
			}
		}
	}

	//puts("\t--------------IMPRESION DE CAMINOS MAS CORTO------------");


	cout << "Distancia mas corta iniciando en vertice\n" <<inicial <<"\n";//Mensaje en pantalla
	for (int i = 1; i <= v; i++) {
		cout << "\t Vertice, distancia mas corta: \n " << i <<"\t" << distancia[i] << "\n";
	}

	cout << "\tPara hallar el camino mas corto del vertice origen al destino:\t"<<endl;
	cout << "\t Ingrese el vertice de destino:\n";
	int destino;
	cin >> destino;
	prinf(destino);
	cout << "\n";
}

/*void cirsc() {//funcion para limpiar el pantalla
	system("pause");
	system("cls");
}*/


int main() {
	int a;
	int E, origen, destino, peso, inicial;
	//int origenO, destinoO, pesoO;
	cout << "\t Bienvenido al programa de grafos para hallar la distancia mas corta de un nodo o vertice al otro: " << endl;
	cout << "\t Ingrese la cantidad de nodos y arcos que contenga el grafo:" << endl;
	cout << "\tIngrese el numero de nodos: ";
	cin >> v;//Almacenamiento de datos
	cout << "\tIngrese el numero de pesos:";
	cin >> E;

	cout << "\tIngrese el nodo o vertice de origen, su arista y la distancia o peso de un nodo a otro:" << endl;
	for (int i = 0; i < E; i++) {
		cout << "Origen: "<<endl; 
		cin >> origen; 
		cout << "Destino: " << endl;
		cin >> destino; 
		cout << "Peso: " << endl;
		cin >> peso;
		//origenO = origen;
		//destinoO = destino;
		//pesoO = peso;

		ady[origen].push_back(Node(destino, peso));//Considermos grafo dirigidos
	}

	cout << "\t Ingrese el vertice inicial:" << endl;
	cin >>inicial;
	cout << "Dikjstra:" << endl;
	dijkstra(inicial);

	//corto(inicial);
	//int E, origen, destino, peso, inicial;//V=Nodos,E=arista
	//v = a;
	//E = 29;
	//int opcion;

	// EN LA LINEA 1
	// 1 2 7
	// 1 4 2
	// 2 4 2
	// 4 2 3
	// 4 3 8 
	// 2 3 1
	// 4 5 5
	// 5 3 5
	// 3 5 4
	//Datos correspondientes a la linea
	/*ady[2].push_back(Node(1, 2));
	ady[1].push_back(Node(2, 2));

	ady[1].push_back(Node(2, 2));
	ady[2].push_back(Node(3, 2));

	ady[4].push_back(Node(3, 3));
	ady[3].push_back(Node(4, 3));

	ady[5].push_back(Node(4, 2));
	ady[4].push_back(Node(5, 2));

	ady[6].push_back(Node(5, 4));
	ady[5].push_back(Node(6, 4));

	ady[7].push_back(Node(6, 2));
	ady[6].push_back(Node(7, 2));
	*/

	return 0;

}