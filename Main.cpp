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

vector<string> tokenizer(string line) {
	vector<string> tokens;
	string temp = "";
	for(int i = 0;i<line.size();i++){
		if(line.at(i)!=','){
			temp+=line.at(i);
		}else{
			tokens.push_back(temp);
			temp="";
		}
	}
	if(temp!=""){
		tokens.push_back(temp);
	}
	return tokens;
}
void leerArchivo() {
	string linea = "";
	ifstream archivoTXT ("Operaciones.txt",ios::in);
	while (getline(archivoTXT, linea)) {
		vector <string> token = tokenizer(linea);
		for(int i = 0; i<token.size(); i++) {
			cout<<token.at(i);
		}
	}
	archivoTXT.close();
}

int main(int argc, char** argv) {
	leerArchivo();
	return 0;
}