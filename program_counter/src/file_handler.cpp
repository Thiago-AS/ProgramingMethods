/** @file file_handler.cpp
 *  @brief Contem as implementações de classes, atributos e metodos utilizados.
 *
 *  @copyright 2018 Thiago Araujo da Silva 15/0149832
 */
#include "../include/file_handler.h"

/** Abre o arquivo de nome passado pelo parametro. Caso arquivo seja aberto
 *  corretamente, retorna verdadeiro, caso contrario falso.
 *
 *  Assertiva de entrada:
 *    - parametro deve ser um string.
 *    - tamanho da string deve ser mairo que zero.
 *
 *  Assertiva de saida:
 *    - resposta correta em função do sucesso da operação.
 */
bool FileHandler::SetFile(string file_name) {
  this->file.open(file_name);
  if (this->file.is_open())
    return true;
  else
    return false;
}

/** Calcula o total de linhas do arquivo, ao fazer uma iteração sobre todas
 *  estas ate atingir o final do arquivo (EOF). Apos todas as operações,
 *  retorna o ponteiro do arquivo para o ponto de começo.
 *
 *  Assertiva de entrada:
 *    - arquivo precisa ja estar aberto.
 *
 *  Assertiva de saida:
 *    - ponteiro arquivo precisa estar no começo.
 *    - valor da quantidade de linhas ser maior que zero.
 */
int FileHandler::GetFileLines() {
  if (this->file.is_open()) {
    string line;
    int amount_lines = 0;
    while (getline(this->file, line)) {
      ++amount_lines;
    }
    this->file.clear();
    this->file.seekg(0, ios::beg);
    return amount_lines;
  } else {
    throw "File is not open";
  }
}

/** Calcula o total de linhas invalidas (comentadas ou em branco). Itera sobre
 *  as linhas procurando por um caractere //, /*.
 *  Caso encontre ambos, verifica sua ordem e realiza operação.
 *  Caso encontre //, verifica se esta no começo da linha, caso esteja
 *  contabiliza como linha invalida.
 *  Caso encontre /*, procura pelo fechamento, enquanto nao encontra, soma
 *  as linhas entre tais pontos como linha invalida.
 *  Caso nao encontre comentarios // ou /*, porem a linha e vazia, contabiliza
 *  como linha invalida.
 *
 *  Assertiva de entrada:
 *    - arquivo precisa ja estar aberto.
 *
 *  Assertiva de saida:
 *    - ponteiro arquivo precisa estar no começo.
 *    - valor da quantidade de linhas ser maior que zero.
 */
int FileHandler::GetInvalidLines() {
  if (this->file.is_open()) {
    string line;
    size_t slash_slash, slash_star, star_slash;
    int amount_invalid_lines = 0;
    while (getline(this->file, line)) {
      line.erase(remove(line.begin(), line.end(), ' '), line.end());
      slash_star = line.find("/*");
      slash_slash = line.find("//");

      // Caso em que existe ambos comentários em uma linha.
      if (slash_star != string::npos && slash_slash != string::npos) {
        // Caso /* apareca primeiro que //
        if (slash_star < slash_slash) {
          // Procura fechamento */, e contabiliza quantidade de linhas
          // comentadas
          amount_invalid_lines++;
          star_slash = line.find("*/");
          while (star_slash == string::npos) {
            amount_invalid_lines++;
            getline(this->file, line);
            star_slash = line.find("*/");
          }
        } else {
          if (slash_slash == 0)
            amount_invalid_lines++;
        }
      }

      // Caso exista somente /*
      if (slash_star != string::npos && slash_slash == string::npos) {
        // Procura fechamento */, e contabiliza quantidade de linhas
        // comentadas
        amount_invalid_lines++;
        star_slash = line.find("*/");
        while (star_slash == string::npos) {
          amount_invalid_lines++;
          getline(file, line);
          star_slash = line.find("*/");
        }
      }

      // Caso exista somente //
      if (slash_star == string::npos && slash_slash != string::npos) {
        if (slash_slash == 0)
          amount_invalid_lines++;
      }

      // Caso nao exista comentario, porem so existe espaco nas linhas
      if (line.size() == 0) {
        amount_invalid_lines++;
      }
    }
    this->file.clear();
    this->file.seekg(0, ios::beg);
    return amount_invalid_lines;
  } else {
    throw "File is not open";
  }
}

/** Contabiliza a quantidade de linhas validas, subtraindo a quantidade de
 *  linhas total e a quantidade de linhas invalidas.
 *
 *  Assertiva de entrada:
 *    - arquivo deve estar aberto
 *
 *  Assertiva de saida:
 *    - valor de linhas maior que zero.
 */
int FileHandler::GetValidLines() {
  if (this->file.is_open()) {
    int amount_valid_lines = 0;
    amount_valid_lines = GetFileLines() - GetInvalidLines();
    return amount_valid_lines;
  } else {
    throw "File is not open";
  }
}

/** Fecha o arquivo previamente aberto.
 *
 *  Assertiva de entrada:
 *    - arquivo deve estar aberto
 *
 *  Assertiva de saida:
 *    - caso arquivo aberto, operação com sucesso
 *    - resposta correta em função do sucesso da operação.
 */
bool FileHandler::CloseFile() {
  if (this->file.is_open()) {
    this->file.close();
    if (this->file.is_open())
      return false;
    else
      return true;
  } else {
    return false;
  }
}
