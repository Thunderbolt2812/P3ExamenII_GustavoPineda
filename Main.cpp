#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//Dato evaluarOperacion(vector<Dato> datos){
//	
//}
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
vector<Dato> ConvertirTokens (vector<string> tokens) {
	vector<Dato> datos;
	Dato obj;
	if(tokens.at(0)=="I") {
		obj.c_tipo='I';
		for(int i = 1; i<tokens.size(); i++) {
			if(tokens.at(i)=="*"||tokens.at(i)=="/"||tokens.at(i)=="+"||tokens.at(i)=="-"){
				obj.valor.operador=tokens.at(i)[0];
			}
			if(tokens.at(i)!="*"&&tokens.at(i)!="/"&&tokens.at(i)!="+"&&tokens.at(i)!="-"){
				obj.valor.i_dato=stoi(tokens.at(i));
			}
		}
		cout<<obj.valor.i_dato<<endl;
	} else if(tokens.at(0)=="F") {
		obj.c_tipo='F';
		for(int i = 1; i<tokens.size(); i++) {
			if(tokens.at(i)=="*"||tokens.at(i)=="/"||tokens.at(i)=="+"||tokens.at(i)=="-"){
				obj.valor.operador=tokens.at(i)[0];
			}
			if(tokens.at(i)!="*"&&tokens.at(i)!="/"&&tokens.at(i)!="+"&&tokens.at(i)!="-"){
				obj.valor.f_dato=atof(tokens.at(i).c_str());
			}
		}
		cout<<obj.valor.f_dato<<endl;
	} else if(tokens.at(0)=="B") {
		obj.c_tipo='B';
		for(int i = 1; i<tokens.size(); i++) {
			if(tokens.at(i)=="*"||tokens.at(i)=="/"||tokens.at(i)=="+"||tokens.at(i)=="-"){
				obj.valor.operador=tokens.at(i)[0];
			}
			if(tokens.at(i)!="*"&&tokens.at(i)!="/"&&tokens.at(i)!="+"&&tokens.at(i)!="-"){
				unsigned long temp = stoul(tokens.at(i),nullptr,10);
				obj.valor.ui_dato=temp;
			}
		}
		cout<<obj.valor.ui_dato<<endl;
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
		ConvertirTokens(tokens);
	}
	archivoTXT.close();
}

int main(int argc, char** argv) {
	leerArchivo();
	return 0;
}