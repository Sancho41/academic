import requests
from getpass import getpass
import re
import pdfkit

def login(matricula, password):

    payload = {
        "txtnumero_matricula": matricula,
        "txtsenha": password,
        "txtsenha_tac": password
    }

    sess = requests.session()
    r = sess.post('http://online.iesb.br/portal/select_login.asp', data=payload)

    if 'Senha / usuário inválido. Tente novamente' in r.text:
        return False
    else:
        sess.post('http://online.iesb.br/aonline/middle_logon.asp', data=payload)

        return sess

if __name__ == "__main__": 
    matricula = "1712130049" # input("Digite sua matrícula: ")
    password = "05947986124" # getpass("Digite a sua senha: ")

    session = login(matricula, password)
    if session:
        r = session.get('http://online.iesb.br/aonline/selecao_boleto.asp')
        cod = re.search('javascript:ValidandoCobrancaProtestoViaAjax\(\'(.+?)\'\);', r.text)
        cod = cod.group(1) if cod else None
        session.post('http://online.iesb.br/aonline/VerificaCobrancaProtesto.asp', {'boleto': cod})

        user_agent = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.122 Safari/537.36'
        headers = {
            'User-Agent': user_agent,
            'Host': 'online.iesb.br',
            'Origin': 'http://online.iesb.br',
            'Referer': 'http://online.iesb.br/aonline/selecao_boleto.asp'
        }

        response = session.post('http://online.iesb.br/aonline/impressao_boleto.asp', {'boleto': cod}, headers=headers)
        print(response.text)
    else:
        print('Usuário ou senha incorretos')