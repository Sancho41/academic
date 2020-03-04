import requests
from getpass import getpass
import re
import pdfkit
import pathlib
from smtplib import SMTP
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication


path = str(pathlib.Path(__file__).parent.absolute())

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

        a = response.text.replace('../', path + '/assets/')
        a = a.replace('images/cortar.GIF', f'{path}/assets/images/cortar.GIF')
        a = '<meta charset="utf-8">' + a
        
        try:
            pdfkit.from_string(a, f'{path}/boleto.pdf')   
        except:
            pass
        

        message = MIMEMultipart()
        message['Subject'] = "Boleto IESB"
        message['From'] = 'gabriel.sancho13@gmail.com'
        message['Reply-to'] = 'gabriel.sancho13@gmail.com'
        message['To'] = 'gabriel.sancho13@gmail.com'

        text = MIMEText("Boleto sege em anexo")
        message.attach(text)

        directory = f'{path}/boleto.pdf'
        print(directory)
        with open(directory, 'rb') as opened:
            openedfile = opened.read()
        attachedfile = MIMEApplication(openedfile, _subtype = "pdf")
        attachedfile.add_header('content-disposition', 'attachment', filename = "boleto.pdf")
        message.attach(attachedfile)

        server = SMTP("smtp.gmail.com", 587)
        server.ehlo()
        server.starttls()
        server.ehlo()
        server.login("gabriel.sancho13@gmail.com", "jgjulyqdaonejdxw")
        server.sendmail(message['From'], message['To'], message.as_string())
        server.quit()
        
    else:
        print('Usuário ou senha incorretos')