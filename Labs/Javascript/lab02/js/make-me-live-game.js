function makeMeLive()
{
    var p = document.getElementsByTagName('p');
    for(var i = 0; i < p.length; i++)
    {
        p[i].innerHTML = `<a href=http://www.${p[i].innerHTML}.com>${p[i].innerHTML}</a>`;
    }
}
