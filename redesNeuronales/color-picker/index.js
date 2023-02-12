function update(color) {
    let val = []; // arreglo de valores rgb
    val.push(color.channel('R'));
    val.push(color.channel('G'));
    val.push(color.channel('B'));

    // console.log(val);

    let div = document.getElementById("sitio");
    div.style.background = color.toHEXString();
}