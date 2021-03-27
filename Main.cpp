#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
union DatoValor {
	unsigned int ui_dato;
	int i_dato;
	float f_dato;
	char operador;
};

struct Dato {
	char c_tipo;
	DatoValor valor;
};
Dato evaluarOperacion(vector<Dato> datos) {
	Dato data;
	Dato resp;
	data = datos.at(0);
	if(data.c_tipo=='I') {
		stack<int> pilaI;
		for(int i = 0; i<datos.size(); i++) {
			Dato data2 = datos.at(i);
			if(data2.c_tipo=='I'){
				pilaI.push(data2.valor.i_dato);
				cout<<data2.valor.i_dato<<" ";
			}
			if(data2.c_tipo=='O') {
				int num1 = pilaI.top();
				pilaI.pop();
				int num2 = pilaI.top();
				pilaI.pop();
				int num3;
				if(data2.valor.operador=='*'){
					num3=num1*num2;
				}
				if(data2.valor.operador=='/'){
					num3=num1/num2;
				}
				if(data2.valor.operador=='+'){
					num3=num1+num2;
				}
				if(data2.valor.operador=='-'){
					num3=num1-num2;
				}
				pilaI.push(num3);				
			}
		}
		resp.valor.i_dato = pilaI.top();
		resp.valor.operador = 'I';
	}
	if(data.c_tipo=='F') {
		stack<float> pilaF;
		for(int i = 0; i<datos.size(); i++) {
			Dato data3 = datos.at(i);
			if(data3.c_tipo=='F'){
				pilaF.push(data3.valor.i_dato);
				cout<<data3.valor.i_dato<<" ";
			}
			if(data3.c_tipo=='O') {
				float num1 = pilaF.top();
				pilaF.pop();
				float num2 = pilaF.top();
				pilaF.pop();
				float num3;
				if(data3.valor.operador=='*'){
					num3=num1*num2;
				}
				if(data3.valor.operador=='/'){
					num3=num1/num2;
				}
				if(data3.valor.operador=='+'){
					num3=num1+num2;
				}
				if(data3.valor.operador=='-'){
					num3=num1-num2;
				}
				pilaF.push(num3);				
			}
		}
		resp.valor.i_dato = pilaF.top();
		resp.valor.operador = 'F';
	}
	if(data.c_tipo=='B') {
		stack<unsigned int> pilaB;
		for(int i = 0; i<datos.size(); i++) {
			Dato data4 = datos.at(i);
			if(data4.c_tipo=='B'){
				pilaB.push(data4.valor.i_dato);
				cout<<data4.valor.i_dato<<" ";
			}
			if(data4.c_tipo=='O') {
				unsigned int num1 = pilaB.top();
				pilaB.pop();
				unsigned int num2 = pilaB.top();
				pilaB.pop();
				unsigned int num3;
				if(data4.valor.operador=='*'){
					num3=num1&num2;
				}
				if(data4.valor.operador=='+'){
					num3=num1|num2;
				}
				pilaB.push(num3);				
			}
		}
		resp.valor.i_dato = pilaB.top();
		resp.valor.operador = 'B';
	}
	return resp;
}
vector<Dato> ConvertirTokens (vector<string> tokens) {
	vector<Dato> datos;
	if(tokens.at(0)=="I") {
		for(int i = 1; i<tokens.size(); i++) {
			Dato obj1;
			char tipo = 'I';
			if(tokens.at(i)=="*"||tokens.at(i)=="/"||tokens.at(i)=="+"||tokens.at(i)=="-") {
				char tipo = 'O';
				obj1.valor.operador=tokens.at(i)[0];
			}
			if(tokens.at(i)!="*"&&tokens.at(i)!="/"&&tokens.at(i)!="+"&&tokens.at(i)!="-") {
				obj1.valor.i_dato=stoi(tokens.at(i));
			}
			obj1.c_tipo=tipo;
			datos.push_back(obj1);
		}
	} else if(tokens.at(0)=="F") {
		for(int i = 1; i<tokens.size(); i++) {
			Dato obj2;
			char tipo='F';
			if(tokens.at(i)=="*"||tokens.at(i)=="/"||tokens.at(i)=="+"||tokens.at(i)=="-") {
				char tipo = 'O';
				obj2.valor.operador=tokens.at(i)[0];
			}
			if(tokens.at(i)!="*"&&tokens.at(i)!="/"&&tokens.at(i)!="+"&&tokens.at(i)!="-") {
				obj2.valor.f_dato=atof(tokens.at(i).c_str());
			}
			obj2.c_tipo=tipo;
			datos.push_back(obj2);
		}
	} else if(tokens.at(0)=="B") {
		for(int i = 1; i<tokens.size(); i++) {
			Dato obj3;
			char tipo='B';
			if(tokens.at(i)=="*"||tokens.at(i)=="/"||tokens.at(i)=="+"||tokens.at(i)=="-") {
				char tipo = 'O';
				obj3.valor.operador=tokens.at(i)[0];
			}
			if(tokens.at(i)!="*"&&tokens.at(i)!="/"&&tokens.at(i)!="+"&&tokens.at(i)!="-") {
				unsigned long temp = stoul(tokens.at(i),nullptr,10);
				obj3.valor.ui_dato=temp;
			}
			obj3.c_tipo=tipo;
			datos.push_back(obj3);
		}
	}
	return datos;
}
vector<string> tokenizador(string line) {
	vector<string> tokens;
	string temp = "";
	for(int i = 0; i<line.size(); i++) {
		if(line.at(i)!=',') {
			temp+=line.at(i);
		} else {
			tokens.push_back(temp);
			temp="";
		}
	}
	if(temp!="") {
		tokens.push_back(temp);
	}
	return tokens;
}
void leerArchivo() {
	string linea = "";
	ifstream archivoTXT ("Operaciones.txt",ios::in);
	while (getline(archivoTXT, linea)) {
		vector <string> tokens = tokenizador(linea);
		for(int i = 0; i<tokens.size(); i++) {
			cout<<tokens.at(i)+" ";
		}
		cout<<endl;
		vector<Dato> datos = ConvertirTokens(tokens);
		Dato data = evaluarOperacion(datos);
		cout<<"Respuesta: "<<data.valor.i_dato<<endl;
	}
	archivoTXT.close();
}

int main(int argc, char** argv) {
	leerArchivo();
	return 0;
}