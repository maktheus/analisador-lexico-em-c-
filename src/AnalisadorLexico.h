#ifndef ANALISADOR_LEXICO_H
#define ANALISADOR_LEXICO_H

#include <fstream>
#include <string>

#include "Token.h"

class AnalisadorLexico {
 public:
  AnalisadorLexico(const std::string& nomeArquivo);
  ~AnalisadorLexico();

  Token Analex();

 private:
  std::ifstream arquivoEntrada_;
  char ch_;
  int linha_;
  int coluna_;

  void ProximoChar();
  void Erro(const std::string& mensagem);
  Token TokenString();
  Token TokenCaractere();
  Token TokenNumero();
  Token TokenBool();
  Token TokenId();
  Token TokenPalavraReservada();
  Token TokenOperador();
  Token TokenPontuacao();
};

#endif
