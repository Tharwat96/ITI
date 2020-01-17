var intervalId ,counter = 0;
var img = document.getElementsByTagName('img')[0];
var src = ['../lab02/img/red.png', '../lab02/img/orange.png', '../lab02/img/green.png'];

function play()
{
    if(!intervalId)
        intervalId = setInterval(intervalCall, 1000);
    function intervalCall()
    {
        img.setAttribute('src', src[counter]);
        if(counter < 2)
            counter++;
        else
            counter = 0;
    }
}

function stop()
{
    clearInterval(intervalId);
    intervalId = undefined;
}

function previous()
{
    stop();
    if(counter === 0)
        counter = 2;
    else if(counter > 0)
        counter--;        
    img.setAttribute('src', src[counter]);

}

function next()
{
    stop();
    if(counter < 2)
        counter++;
    else
        counter = 0;    
    img.setAttribute('src', src[counter]);

}

function showFirst(){
    counter = 0;
    img.setAttribute('src', src[counter]);
}

function showLast(){
    counter = 2;
    img.setAttribute('src', src[counter]);
}

var buttons = document.getElementsByTagName("button");
buttons[0].addEventListener("click", play);
buttons[1].addEventListener("click", stop);
buttons[2].addEventListener("click", showFirst); //first arrow
buttons[3].addEventListener("click", previous); //previous button
buttons[4].addEventListener("click", next); //next button
buttons[5].addEventListener("click", showLast); //last arrow