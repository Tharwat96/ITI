function readyGo(n)
{
    for(var i=0; i < 3; i++)
        document.getElementsByTagName('img')[i].setAttribute('src', "../lab02/img/gray.png");
    var src = ['../lab02/img/red.png', '../lab02/img/orange.png', '../lab02/img/green.png'];
    var color = ['red', 'orange', 'green'];
    var status = ['Ready', 'Steady', 'Go'];
    var img = document.getElementsByTagName('img')[n-1];
    img.setAttribute('src', src[n-1]);
    var message = document.getElementsByClassName('message')[0];
    console.log(message);
    message.textContent = status[n-1];
    message.style.color = color[n-1];
}