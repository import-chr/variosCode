let hh = document.querySelector('#hh');
let mm = document.querySelector('#mm');
let ss = document.querySelector('#ss');

setInterval(() => {
    let time = new Date();
    let hr = time.getHours() * 30;
    let mn = time.getMinutes() * 6;
    let sc = time.getSeconds() * 6;

    hh.style.transform = `rotateZ(${hr + (mn / 12)}deg)`;
    mm.style.transform = `rotateZ(${mn}deg)`;
    ss.style.transform = `rotateZ(${sc}deg)`;
});