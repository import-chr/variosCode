let network = new brain.NeuralNetwork();

network.train([
    // entrada color oscuro -> texto color blanco
    {input: {red: 0, green: 0, blue: 0}, output: {color: 1}},
    // entrada color claro -> texto color negro
    {input: {red: 1, green: 1, blue: 1}, output: {color: 0}},
    {input: {red: 1, green: 0, blue: 0.25}, output: {color: 1}},
    {input: {red: 0.18, green: 0.2, blue: 1}, output: {color: 1}}
]);

function update(color) {
    let val = []; // arreglo de valores rgb
    val.push(color.channel('R'));
    val.push(color.channel('G'));
    val.push(color.channel('B'));

    // console.log(val);

    let div = document.getElementById("sitio");
    div.style.background = color.toHEXString();

    let inp = {
        red: val[0] / 255,
        green: val[1] / 255,
        blue: val[2] / 255
    };

    let result = network.run(inp);
    // console.log(result);

    if(result.color > 0.5) {
        div.style.color = "#fff";
    } else {
        div.style.color = "#000";
    }
}