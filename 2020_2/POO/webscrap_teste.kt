
import com.google.gson.GsonBuilder
import org.jsoup.Connection
import org.jsoup.Jsoup
import java.nio.charset.Charset

fun main() {
    val login = Jsoup.connect("http://online.iesb.br/aonline/middle_logon.asp")
        .data("txtnumero_matricula", "1712130049")
        .data("txtsenha_tac", "Tanchu_41")
        .method(Connection.Method.POST)
        .execute()

    val authCookies = login.cookies()

    val boletim = Jsoup.connect("http://online.iesb.br/aonline/notas_freq_boletim_iframe.asp")
        .cookies(authCookies)
        .get()

    boletim.charset(Charset.forName("windows-1252"))

    val headers = boletim
        .select("#Open_Text_General > thead > :nth-child(2) > th")
        .map {
            it.text()
        }

    val rows = boletim
        .select("#Open_Text_General > tbody > tr")

    val lista = rows.map {
        val materies: MutableMap<String, String> = mutableMapOf()
        val row = it.select("td")
        for ((index, head) in headers.withIndex())
            materies[head] = row[index].text()
        materies
    }

    val gson = GsonBuilder().setPrettyPrinting().create()

    val json = gson.toJson(lista)
    println(json)

}
