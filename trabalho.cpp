#include <bits/stdc++.h>
#include <cctype>

using namespace std;

string arq = "dadostrab.txt";

class Aluno{
    public:
        string cpf;
        string nome;
        string codigo;

};

class Disciplina{
    public:
        string nome;
        string codigo;
        string professor;
        string creditos;
        string periodo;
};

class Matricula{
    public:
        string codalu;
        string coddis;
        string periodo;
};

//Vetores globais
vector<Aluno> lista_alunos;
vector<Disciplina>  lista_disciplina;
vector<Matricula> lista_matricula;


void menu(){
    cout << "\n\n\tMENU ESCOLAR\n" << endl;
    cout << endl;
    cout << "1 - Cadastrar Aluno" << endl;
    cout << "2 - Cadastrar Disciplina" << endl;
    cout << "3 - Remover Aluno" << endl;
    cout << "4 - Remover disciplina" << endl;
    cout << "5 - Cadastrar Aluno em uma Disciplina" << endl;
    cout << "6 - Consultar Disciplinas de um aluno" << endl;
    cout << "7 - Consultar alunos em uma Disciplina" << endl;
    cout << "8 - Consultar Disciplinas cadastradas" << endl;
    cout << "9 - Consultar Alunos cadastrados" << endl;
    cout << "10 - Salvar" << endl;
    cout << "0 - Sair" << endl;
    cout << "Resposta: "; 
}
void ler_arquivo(){
    ifstream arquivo;
    arquivo.open(arq);
    if (!arquivo.is_open()){
        cout << "Arquivo não encontrado" << endl;
    }
    string linha;
    while(getline(arquivo, linha)){
        istringstream ss(linha); // Cria um stringstream com a linha atual

        string tipo; 
        string codigo1; 
        string codigo2;
        string nome; 
        string cpf; 
        string prof;
        string creditos;
        string periodo;

        ss >> tipo; //Armazena a primeira palavra da linha
        if (tipo == "Aluno") {  // Verifica se a primeira palavra é "Aluno"
            ss >> codigo1 >> nome >> cpf;
            Aluno aluno;
            aluno.codigo = codigo1;
            aluno.nome = nome;
            aluno.cpf = cpf;
            lista_alunos.push_back(aluno); // Adiciona todas as linhas que começam com Aluno no vetor lista_alunos
        }
        if (tipo == "Disciplina"){
            ss >> codigo2 >> nome >> prof >> creditos >> periodo;
            Disciplina disciplina;
            disciplina.codigo = codigo2;
            disciplina.nome = nome;
            disciplina.professor = prof;
            disciplina.creditos = creditos;
            disciplina.periodo = periodo;
            lista_disciplina.push_back(disciplina); // Adiciona todas as linhas que começam com Disciplina no vetor lista_disciplinas
        }
        if (tipo == "Matricula"){
            ss >> codigo1 >> codigo2 >> periodo;
            Matricula matricula;
            matricula.codalu = codigo1;
            matricula.coddis = codigo2;
            matricula.periodo = periodo;
            lista_matricula.push_back(matricula); // Adiciona todas as linhas que começam com Matricula no vetor lista_matriculas
        }
    }
    arquivo.close();
}
bool unicidade(string cod){
    if (cod.length() == 5){ //Verifica se o codigo tem 5 caracteres
        for (size_t i = 0; i < lista_alunos.size(); i++){ // Verificando se o aluno ja é cadastrado //
            if (cod == lista_alunos[i].codigo){
                return false;
            }
        }
    }
    if (cod.length() == 4){ //Verifica se o codigo tem 4 carcteres
        for (size_t i = 0; i < lista_disciplina.size(); i++){ // Verificando se a disciplina ja é cadastrada //
            if (cod == lista_disciplina[i].codigo){
                return false;
            }
        }
    }
    return true;
}
void cadastrar_aluno(){
    Aluno aluno;
    cout << "Digite o codigo do aluno (5 digitos)" << endl;
    cin >> aluno.codigo;
    while (aluno.codigo.length() != 5){
        cout << "Digite o codigo do aluno (5 digitos)" << endl;
        cin >> aluno.codigo;
    }
    if (unicidade(aluno.codigo)){ 
        cout << "Digite o nome do aluno" << endl;
        cin >> aluno.nome;
        cout << "Digite o cpf do aluno" << endl;
        cin >> aluno.cpf;
        while(aluno.cpf.length() != 11){
            cout << "Digite o cpf do aluno (11 digitos)" << endl;
            cin >> aluno.cpf;
        }
        lista_alunos.push_back(aluno);
    }
    else{
        cout << "Aluno ja cadastrado" << endl;
    }
}
void cadastrar_disciplina(){
    Disciplina disciplina;
    cout << "Digite o código da disciplina" << endl;
    cin >> disciplina.codigo;
    if (unicidade(disciplina.codigo)){
        cout << "Digite o nome da disciplina" << endl;
        cin >> disciplina.nome;
        cout << "Digite o professor da disciplina" << endl;
        cin >> disciplina.professor;
        cout << "Digite o número de creditos" << endl;
        cin >> disciplina.creditos;
        cout << "DIgite o periodo da discrimina" << endl;
        cin >> disciplina.periodo;
        lista_disciplina.push_back(disciplina);
    }
    else cout << "Disciplina ja cadastrada" << endl;

}
void remover_aluno(){
    int k = 10;
    string cod;
    cout << "Digite o codigo do aluno" << endl;
    cin >> cod;
    for (size_t i = 0; i < lista_alunos.size(); i++){
        if (cod == lista_alunos[i].codigo){
            k = 11;
            cout << "Aluno " << lista_alunos[i].codigo << " removido" << endl;
            lista_alunos.erase(lista_alunos.begin() + i);
        }
    }
    if (k == 10) cout << "Aluno nao encontrado" << endl;
}
void remover_disciplina(){
    int k = 10;
    string cod;
    for (size_t i = 0; i < lista_disciplina.size(); i++){
        if (cod == lista_disciplina[i].codigo){
            k = 11;
            lista_disciplina.erase(lista_disciplina.begin() + i);
        }
    }
    if (k == 10) cout << "Disciplina nao encontrada" << endl;
}
void alunos_cadastrados(){
    ifstream arquivo;
    arquivo.open(arq);
    if (!arquivo.is_open()){
        cout << "Arquivo não encontrado" << endl;
    }
    cout << "\tALUNOS CADASTRADOS\t" << endl;
    string linha;
    int i = 1;
    while (getline(arquivo, linha)){
        istringstream ss(linha);
        string tipo;
        string codigo;
        string nome;
        string cpf;
        ss >> tipo;
        if (tipo == "Aluno"){
            ss >> codigo >> nome >> cpf;
            cout << "//  Aluno " << i << "  //  " << "CODIGO: " << codigo << ", " << "NOME: " << nome << ", " << "CPF: " << cpf << endl;
        }
        i++;
    }
}
void disciplinas_cadastradas(){
    ifstream arquivo;
    arquivo.open(arq);
    if (!arquivo.is_open()){
        cout << "Arquivo não encontrado" << endl;
    }
    cout << "\tDISCIPLINAS CADASTRADAS\t" << endl;
    string linha;
    int i = 1 - lista_alunos.size();
    while (getline(arquivo, linha)){
        istringstream ss(linha);
        string tipo;
        string codigo;
        string nome;
        string prof;
        string creditos;
        string periodo;
        ss >> tipo;
        if (tipo == "Disciplina"){
            ss >> codigo >> nome >> prof >> creditos >> periodo;
            cout << "//  Disciplina " << i << "  //  " << "CODIGO: " << codigo << ", " << "NOME: " << nome << ", " << "PROFESSOR: " << prof << ", " << "CREDITOS: " << creditos << ", " << "PERIODO: " << periodo << endl;
        }
        i++;
    }
}
void salvar(){
    ofstream arquivo;
    arquivo.open(arq);
    if (!arquivo.is_open()){
        cout << "Arquivo não encontrado" << endl;
    }
    string linha;
    for (size_t i = 0; i < lista_alunos.size(); i++){
        arquivo << "Aluno " << lista_alunos[i].codigo << " " << lista_alunos[i].nome << " " << lista_alunos[i].cpf << endl;
    }
    for (size_t i = 0; i < lista_disciplina.size(); i++){
        arquivo << "Disciplina " << lista_disciplina[i].codigo << " " << lista_disciplina[i].nome << " " << lista_disciplina[i].professor << " " << lista_disciplina[i].creditos << " " << lista_disciplina[i].periodo << endl;
    }
    for (size_t i = 0; i < lista_matricula.size(); i++){
        arquivo << "Matricula " << lista_matricula[i].codalu << " " << lista_matricula[i].coddis << " " << lista_matricula[i].periodo << endl;
    }
}
void cadastrar_aluno_em_disciplina(){
    string alu_cod;
    string dis_cod;
    int k1 = -10;
    int k2 = -10;
    cout << "Digite o codigo do aluno" << endl;
    cin >> alu_cod;
    cout << "Digite o codigo da disciplina" << endl;
    cin >> dis_cod;
    for (size_t i = 0; i < lista_alunos.size(); i++){
        if (alu_cod == lista_alunos[i].codigo)
            k1 = i;
    }
    for (size_t i = 0; i < lista_disciplina.size(); i++){
        if (dis_cod == lista_disciplina[i].codigo)
            k2 = i;
    }
    if (k1 == -10 || k2 == -10) cout << "Aluno ou disciplina não encontrado" << endl;
    else{
        Matricula matricula;
        matricula.codalu = lista_alunos[k1].codigo;
        matricula.coddis = lista_disciplina[k2].codigo;
        matricula.periodo = lista_disciplina[k2].periodo;
        lista_matricula.push_back(matricula);
        cout << "Aluno " << lista_alunos[k1].nome << " foi matriculado na disciplina de " << lista_disciplina[k2].nome << " no periodo " << lista_disciplina[k2].periodo << endl;
    }
}
void alunos_da_disciplina_de_um_periodo(){
    string per;
    cout << "Digite o periodo que voce quer consultar" << endl;
    cin >> per;
    int cont = 0;
    cout << "\n\n\tDISCIPLINAS CADASTRADAS NO PERIODO " << per << "\n\n" << endl;
    for (size_t i = 0; i < lista_disciplina.size(); i++){
        if (per == lista_disciplina[i].periodo){
            cont++;
            cout << "Digite " << lista_disciplina[i].codigo << " para consultar os alunos da disciplna " << lista_disciplina[i].nome << endl;
        }
    }
    if (cont == 0) cout << "NUNHUMA DISCIPLINA ENCONTRADA" << endl;
    else{
        string resposta;
        cout << "\n\nResposta: ";
        cin >> resposta;
        cout << endl;
        for (size_t i = 0; i < lista_matricula.size(); i++){
            if (resposta == lista_matricula[i].coddis && per == lista_matricula[i].periodo){
                for (size_t j = 0; j < lista_alunos.size(); j++){
                    if (lista_matricula[i].codalu == lista_alunos[j].codigo){
                        cout << "Aluno " << lista_alunos[j].nome << endl;
                        break;
                    }
                }
            }
        }
    }
}
void disciplinas_de_um_aluno_em_um_periodo(){
    alunos_cadastrados();
    string resposta1;
    cout << "\nDigite o codigo do aluno que deseja visualizar as disciplinas: ";
    cin >> resposta1;
    for (size_t i = 0; i < lista_alunos.size(); i++){
        if (resposta1 == lista_alunos[i].codigo){
            cout << "\n\n\tDisciplinas do aluno " << lista_alunos[i].nome << "\n\n" << endl;
            break;
        }
    }
    cout << "CODIGO  PERIODO" <<endl; 
    for (size_t i = 0; i < lista_matricula.size(); i++){
        if (resposta1 == lista_matricula[i].codalu){
            cout << lista_matricula[i].coddis << "  " <<lista_matricula[i].periodo << "\n" <<endl;
        }
    }
    string resposta2;
    cout << "Digite o periodo desejado: ";
    cin >> resposta2;
    cout << endl;
    cout << "\tDisciplinas do Aluno " << resposta1 << " no Periodo " << resposta2 << endl;
    for (size_t i = 0; i < lista_matricula.size(); i++){
        if (resposta2 == lista_matricula[i].periodo && resposta1 == lista_matricula[i].codalu){
            cout << lista_matricula[i].coddis << endl;
        }
    }
}
int main(){
    int escolha;
    ler_arquivo();
    menu();
    cin >> escolha;
    if (escolha == 1) cadastrar_aluno();
    else if (escolha == 2) cadastrar_disciplina();
    else if (escolha == 3) remover_aluno();
    else if (escolha == 4) remover_disciplina();
    else if (escolha == 5) cadastrar_aluno_em_disciplina();
    else if (escolha == 6) disciplinas_de_um_aluno_em_um_periodo();
    else if (escolha == 7) alunos_da_disciplina_de_um_periodo();
    else if (escolha == 8) disciplinas_cadastradas();    
    else if (escolha == 9) alunos_cadastrados();
    salvar();
    return 0;
}

