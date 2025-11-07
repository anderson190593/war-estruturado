🎲 War Estruturado em C
Este projeto é uma implementação simplificada e modular do jogo War, desenvolvido em linguagem C como parte de um curso de estrutura de dados. O objetivo é aplicar conceitos fundamentais como structs, ponteiros, alocação dinâmica de memória, modularização e lógica condicional, culminando em um sistema de jogo estratégico com missões personalizadas.

📌 Objetivos do Projeto
- Criar uma base de dados de territórios utilizando structs
- Simular ataques entre territórios com rolagem de dados
- Atribuir missões estratégicas aos jogadores de forma dinâmica
- Verificar condições de vitória com base nas missões
- Praticar modularização, ponteiros e gerenciamento de memória

🛠️ Tecnologias Utilizadas
- Linguagem: C
- Bibliotecas: stdio.h, stdlib.h, string.h, time.h
- Ferramentas: compilador GCC ou qualquer ambiente C compatível

🧱 Estrutura do Código
O código está dividido em funções específicas para garantir clareza, reutilização e manutenção:
|  |  | 
| main() |  | 
| atribuirMissao() |  | 
| exibirMissao() |  | 
| atacar() |  | 
| verificarMissao() |  | 
| exibirMapa() |  | 
| liberarMemoria() |  | 



🧠 Conceitos Aplicados
- struct: definição da estrutura Territorio com nome, cor e tropas
- Vetores de structs: armazenamento de múltiplos territórios
- Ponteiros: manipulação dinâmica de missões
- malloc e free: alocação e liberação de memória
- Modularização: separação lógica em funções
- rand() e srand(): geração de números aleatórios para simular dados
- Passagem por valor e referência: controle de dados entre funções

🎯 Missões Estratégicas
As missões são sorteadas automaticamente no início do jogo. Exemplos:
- Conquistar 3 territórios seguidos
- Eliminar todas as tropas da cor vermelha
- Controlar todos os territórios com mais de 10 tropas
- Ter pelo menos 3 territórios com cor azul
- Reduzir qualquer território inimigo a 0 tropas
Cada missão é armazenada dinamicamente e verificada ao final de cada turno.

🧪 Como Executar
- Clone o repositório:
git clone https://github.com/seu-usuario/war-estruturado.git
cd war-estruturado
- Compile o código:
gcc war.c -o war
- Execute o jogo:
./war



📷 Demonstração
===== TURNO 1 =====
Território 1: Brasil | Cor: azul | Tropas: 10
Território 2: Argentina | Cor: vermelha | Tropas: 8
...
Rolagem do atacante: 5
Rolagem do defensor: 3
Vitória do atacante!
Missão cumprida! Você venceu o jogo!



📚 Aprendizado
Este projeto foi desenvolvido como parte de um curso de estrutura de dados com foco em:
- Organização de dados com structs
- Manipulação de memória dinâmica
- Criação de sistemas interativos em C
- Simulação de lógica de jogos

📄 Licença
Este projeto está licenciado sob a MIT License.
