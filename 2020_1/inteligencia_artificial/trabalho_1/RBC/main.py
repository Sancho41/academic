from classificacoes import classificacoes

notas = [
  ('texto_tecnico', 0),
  ('texto_direto', .5),
  ('texto_contextualizado', .5),
  ('texto_com_imagens', 1),
  ('audio_podcast', 1),
  ('audio_livro', .5),
  ('video_aula', 1),
  ('video_animacao', .5)
]

tend = {
  'direta': 0,
  'mediana': 0,
  'visual': 0
}

for nota in notas:
  categoria, percent = nota
  priorities = classificacoes[categoria]['priority']
  maior, media, menor = priorities

  if percent < .33:
    tend[menor] += 1
  elif percent < .66:
    tend[media] += 1
  else:
    tend[maior] += 1

for i in tend:
  print(i, (tend[i] * 100) / len(notas))