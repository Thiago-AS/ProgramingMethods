/** @file file_handler.h
 *  @brief Contem as declarações de classes, atributos e metodos utilizados.
 *
 *  @copyright 2018 Thiago Araujo da Silva 15/0149832
 */
#ifndef PROGRAM_COUNTER_INCLUDE_FILE_HANDLER_H_
#define PROGRAM_COUNTER_INCLUDE_FILE_HANDLER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <algorithm>

using std::string;
using std::iostream;
using std::ifstream;
using std::ios;

/** @brief Classe que trata de todas as operações executadas no arquivo.
 */
class FileHandler {
 public:
  /** Atributo que guarda o arquivo a ser manipulado. */
  ifstream file;

  /** @brief Define e abre o arquivo fornecido.
   *
   *  @param file_name Nome do arquivo a ser lido.
   *  @return bool Retorna verdadeiro para operação bem sucedida e falso caso
   *  contrario.
   */
  bool SetFile(string file_name);

  /** @brief Calcula a quantidade total de linhas do arquivo.
   *
   *  @return int Retorna o valor da quantidade total de linhas.
   */
  int GetFileLines();

  /** @brief Calcula a quantidade de linhas comentadas ou em branco.
   *
   *  @return int Retorna o valor da quantidade de linhas invalidas.
   */
  int GetInvalidLines();

  /** @brief Calcula a quantidade de linhas validas (codigo).
   *
   *  @return int Retorna o valor da quantidade de linhas validas.
   */
  int GetValidLines();

  /** @brief Fecha o arquivo previamente aberto.
   *
   *  @return bool Retorna verdadeiro para operação bem sucedida e falso caso
   *  contrario.
   */
  bool CloseFile();
};

#endif  // PROGRAM_COUNTER_INCLUDE_FILE_HANDLER_H_
