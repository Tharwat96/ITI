var ns = 'http://www.w3.org/2000/svg'
var div = document.querySelector("#my-svg")
var svg = document.createElementNS(ns, 'svg')
svg.setAttribute('width', '100%')
svg.setAttribute('height', '100%')
div.appendChild(svg)
var btns = document.getElementsByTagName('input');
btns[0].addEventListener('click', e => {
    var line = document.createElementNS(ns, 'line')
    line.setAttribute('x1', 100)
    line.setAttribute('y1', 100)
    line.setAttribute('x2', 300)
    line.setAttribute('y2', 300)
    line.setAttribute('stroke', "purple");

    svg.appendChild(line);

})

btns[1].addEventListener('click', e => {

    var rect = document.createElementNS(ns, 'rect');
    rect.setAttribute('width', 100);
    rect.setAttribute('height', 100);
    rect.setAttribute('fill', '#f06');
    svg.appendChild(rect);
})

btns[2].addEventListener('click', e=>{
    var circle = document.createElementNS(ns, 'circle');
    circle.setAttribute('cx', 380);
    circle.setAttribute('cy', 350);
    circle.setAttribute('r', 100);
    circle.setAttribute('stroke', 50);
    svg.appendChild(circle);
})

