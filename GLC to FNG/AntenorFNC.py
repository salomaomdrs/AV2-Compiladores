gramatica = {
    "S": ["AB", "CSB"],
    "A": ["aB", "C"],
    "B": ["bbB", "b"]
}

def fng(gramatica):
  gramatica_aux = gramatica
  valores_removidos = []
  for chave, valores in gramatica_aux.items():
    for i, valor in enumerate(valores):
      if len(valor) == 1 and valor.isupper():
        valores_removidos.append(valor)
        valores[i] = ""
    valores = list(filter(None, valores))
    
  for chave, valores in gramatica_aux.items():
    for i in range(len(valores)):
      for removido in valores_removidos:
        if removido in valores[i]:
          valores[i] = ""
        
    valores = list(filter(None, valores))
    gramatica_aux[chave] = valores
  nova_chave= {}
  cont=1
  for chave,valor in gramatica_aux.items():
      nova_chave[chave]= 'A' + str(cont)
      cont+=1
  gramatica_aux=expandir_gramatica(gramatica_aux)
  gramatica_aux=substituir_objetos(gramatica_aux,nova_chave)
  return gramatica_aux

def expandir_gramatica(gramatica):
    nova_gramatica = {}
    for variavel in gramatica:
      producoes = gramatica[variavel]
      novas_producoes = []
      for producao in producoes:
        if producao[0].isupper():
          if producao[0] in gramatica:
            novas_producoes.extend([subproducao + producao[1:] for subproducao in gramatica[producao[0]]])
        else:
          novas_producoes.append(producao)
      nova_gramatica[variavel] = novas_producoes
    return nova_gramatica

def substituir_objetos(gramatica, objetos):
    nova_gramatica = {}
    for variavel in gramatica:
        producoes = gramatica[variavel]
        novas_producoes = []
        for producao in producoes:
            nova_producao = ""
            for simbolo in producao:
                if simbolo.isupper():
                    if simbolo in objetos:
                        nova_producao += objetos[simbolo]
                else:
                    nova_producao += simbolo
            novas_producoes.append(nova_producao)
        nova_gramatica[objetos[variavel]] = novas_producoes
    return nova_gramatica

print(fng(gramatica))