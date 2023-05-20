# Trabalho-SO
Parte do relatório::

Seja criativo! Monte tabelas, gráficos, etc. Avalie/critique o máximo possível os resultados dos testes. Faça conjecturas e verifique, com testes, se elas estão certas.
Elabore gráficos relativo ao tempo de processamento versus diferentes números de threads e tamanhos de macroblocos,
conforme citado anteriormente. Você encontrará resultados bem interessantes quando o tamanho dos macroblocos for muito
grande ou muito pequenos! Mas, lembre-se de testar isoladamente a influência de cada um desses parâmetros.
Igualmente, verifique se há algum ganho/perda quando o número de threads for maior que o número de núcleos de
processamento.

Testes e Análises obrigatórias
• Mensure o speedup ao rodar em múltiplas threads. Analise se esse resultado está coerente com o que a Lei de Amdahl
prevê. Mas atenção a diferença entre núcleos físicos e núcleos lógicos (ou virtuais)! O speedup deve ser calculado em
cada caso e claramente identificado no relatório do trabalho.
• Teste em dois computadores bem diferentes, tal qual feito em AOC. Compare o desempenho.
• Aumente muito o número de threads (algumas centenas ou mais) a fim de que o overhead possa realmente ficar
crítico e analise os resultados. Nesse caso, mantenha fixo o tamanho do macrobloco.
• Remova os mutexes que protegem as Regiões Críticas. Isso mesmo... remova as proteções temporariamente, rode o
programa com macroblocos pequenos (por quê?) e observe os resultados.
CONCLUSÃO
Pronto, chegou a hora de você responder da maneira mais abrangente possível a simples questão:
O que você pode aprender com esse trabalho?

