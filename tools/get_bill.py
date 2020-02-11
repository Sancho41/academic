import requests
from getpass import getpass

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
    matricula = input("Digite sua matrícula: ")
    password = getpass("Digite a sua senha: ")

    session = login(matricula, password)
    if session:
        print('Logado')
    else:
        print('Usuário ou senha incorretos')