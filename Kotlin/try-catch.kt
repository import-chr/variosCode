fun main(args: Array<String>) {
    var nombre : String? = null

    try {
        // nombre!!.length
        throw NullPointerException("Referencia nula")
    } catch(exception : NullPointerException) {
        println("Ha ocurrido un error")
    } finally {
        pintln("Error... Cerrando aplicacion")
    }
}