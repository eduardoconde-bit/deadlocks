EN05213 - Laboratório de Sistemas Operacionais

Tema: Impasses / Deadlocks
Professor: Prof. Dr. Marcos Amaris
Data: 6 de Setembro de 2024
Objetivo

O objetivo desta atividade é proporcionar uma compreensão prática sobre o problema de impasse (deadlock) e as técnicas de prevenção, evitação e detecção em sistemas operacionais. Em pares, os alunos irão implementar uma simulação de deadlock e experimentar formas de evitar ou resolver o problema.
Parte 1: Simulação de um Deadlock
Descrição

Nesta etapa, os alunos devem criar um cenário onde dois ou mais processos competem por recursos que estão sendo mantidos mutuamente, resultando em um estado de impasse. O objetivo é que os processos entrem em um estado de deadlock.
Tarefas

  Criar um programa em C ou C++ que inicialize dois ou mais threads ou processos que tentam adquirir dois recursos compartilhados.
  Fazer com que os processos adquiram os recursos em ordem reversa, por exemplo:
  Processo A tenta adquirir o Recurso 1 e, em seguida, o Recurso 2.
  Processo B tenta adquirir o Recurso 2 e, em seguida, o Recurso 1.
  Certificar-se de que os processos entram em um estado de deadlock.

Dicas de Implementação

  Utilizar mutexes (locks de exclusão mútua) ou semáforos para simular a alocação de recursos.
  Para sistemas Linux, utilize as funções pthread_mutex_lock e pthread_mutex_unlock (para threads).

Parte 2: Detecção e Resolução de Impasses
Descrição

Após a simulação do impasse, o próximo passo é entender como os sistemas operacionais detectam e resolvem esses problemas.
Tarefas

  Modificar o programa para implementar uma solução de detecção de impasse.
  Ao detectar um impasse, o programa deve:
  Imprimir uma mensagem indicando que o impasse ocorreu.
  Tentar liberar os recursos envolvidos para que os processos possam avançar.

Dicas de Implementação

  Adicionar um contador que monitore o tempo que os processos ficam bloqueados.
  Se o tempo de espera exceder um limite pré-definido, o programa deve assumir que há um impasse e tomar ações corretivas (por exemplo, liberar recursos manualmente).

Parte 3: Prevenção e Evitação de Impasses
Descrição

Além de detectar impasses, existem técnicas que podem ser usadas para prevenir ou evitar que eles ocorram.
Tarefas

  Modificar o programa para garantir que os processos adquiram os recursos na mesma ordem, prevenindo a condição de espera circular.
  Implementar uma técnica de prevenção de impasse. Opcionalmente, discuta como o algoritmo do banqueiro poderia ser implementado para evitar impasses.

Entrega

  O relatório deve ser feito em pares e conter:
      A explicação do que é um impasse, quando ele ocorre e como o programa o simula.
      A implementação das técnicas de detecção e prevenção de impasses, com os algoritmos utilizados.
      Capturas de tela ou logs do programa demonstrando o deadlock e as soluções aplicadas.
  O arquivo PDF com o relatório e os códigos dos exercícios deve ser submetido no SIGAA até sexta-feira, 13 de Setembro, antes do horário da aula.
