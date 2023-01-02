#include <cctype>
#include <iostream>
#include <sstream>

#include "AnalisadorLexico.h"

AnalisadorLexico::AnalisadorLexico(const std::string &nomeArquivo)
    : arquivoEntrada_(nomeArquivo), linha_(1), coluna_(0)
{
    if (arquivoEntrada_.fail())
    {
        std::cerr << "Erro ao abrir arquivo: " << nomeArquivo << std::endl;
        exit(1);
    }
    ProximoChar();
}

AnalisadorLexico::~AnalisadorLexico()
{
    arquivoEntrada_.close();
}

Token AnalisadorLexico::Analex()
{
    while (isspace(ch_))
        ProximoChar();

    if (ch_ == EOF)
        return Token{FIM_ARQUIVO, ""};
    if (ch_ == '/')
    {
        ProximoChar();
        if (ch_ == '/')
        {
            do
            {
                ProximoChar();
            } while (ch_ != '\n' && ch_ != EOF);
            return Analex();
        }
        if (ch_ == '*')
        {
            do
            {
                ProximoChar();
                if (ch_ == '*')
                {
                    ProximoChar();
                    if (ch_ == '/')
                    {
                        ProximoChar();
                        break;
                    }
                }
            } while (ch_ != EOF);
            return Analex();
        }
        return Token{ERRO, "/"};
    }
    if (ch_ == '"')
        return TokenString();
    if (ch_ == '\'')
        return TokenCaractere();
    if (isdigit(ch_))
        return TokenNumero();
    if (ch_ == 't' || ch_ == 'f')
        return TokenBool();
    if (isalpha(ch_) || ch_ == '_' || ch_ == '$')
        return TokenId();
    if (ispunct(ch_))
        return TokenOperador();
    return Token{ERRO, std::string(1, ch_)};
}

void AnalisadorLexico::ProximoChar()
{
    if (ch_ == '\n')
    {
        linha_++;
        coluna_ = 0;
    }
    else
    {
        coluna_++;
    }
    arquivoEntrada_.get(ch_);
}

void AnalisadorLexico::Erro(const std::string &mensagem)
{
    std::cerr << "Erro na linha " << linha_ << ", coluna " << coluna_ << ": "
              << mensagem << std::endl;
    exit(1);
}

Token AnalisadorLexico::TokenString()
{
    std::string lexema;
    ProximoChar();
    while (ch_ != '"' && ch_ != EOF)
    {
        if (ch_ == '\\')
        {
            ProximoChar();
            if (ch_ == 'n')
                lexema += '\n';
            else if (ch_ == 't')
                lexema += '\t';
            else if (ch_ == '\\')
                lexema += '\\';
            else if (ch_ == '"')
                lexema += '"';
            else if (ch_ == '\'')
                lexema += '\'';
            else
                Erro(std::string("Caractere de escape inválido: \\") + ch_);
        }
        else
        {
            lexema += ch_;
        }
        ProximoChar();
    }
    if (ch_ == EOF)
        Erro("String incompleta");
    else
        ProximoChar();
    return Token{STRING, lexema};
}
