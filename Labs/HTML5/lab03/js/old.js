var addBtn = document.querySelector('#add-task');
var input = document.querySelector('#new-task');
var listHtml = document.querySelector('#tdl-list');
var ol = document.createElement('ol');
listHtml.appendChild(ol);
listArr = new Array();
checkedArr = new Array();
var chkboxes, chkdboxes;
var deleteBtns;
if(!localStorage.arr)
{
    addListToLocalStorage(listArr);
}else{
    listArr = JSON.parse(localStorage.arr);
}
if(!localStorage.checkedArr)
{
    addCheckedToLocalStorage(checkedArr);
}else{
    checkedArr = JSON.parse(localStorage.checkedArr);
}

function showList(){
    /**print list and buttons */
    /**for unchecked items: */

    for(let i = 0; i<listArr.length; i++) {
        ol.innerHTML += `<li><input type="checkbox" class="chkbox" data-index="${i}">${listArr[i]}<input type="button" class="deleteBtns" data-index="${i}" value="X"></li>`;
    }
    // ol.innerHTML += "<p>---------checked items-------</p>"
    /**for checked items: */

    // for(let i = 0; i<checkedArr.length; i++) {
    //     ol.innerHTML += `<li><input type="checkbox" class="chkdbox" data-index="${i}" checked="true"><strike>${checkedArr[i]}</strike><input type="button" class="deleteBtns" data-index="${i}" value="X"></li>`;
    // }

    /**manage event listeners */
    /**for unchecked items: */
    // for(let i = 0; i<listArr.length; i++){
    //     chkboxes = document.querySelectorAll(".chkbox");
    //     // console.log(chkboxes[i].dataset.index)
    //     deleteBtns = document.querySelectorAll(".deleteBtns");
    //     chkboxes[i].onchange = checkEvent;
    // }

    /**for checked items: */
    // for(let i = 0; i<checkedArr.length; i++){
    //     chkdboxes = document.querySelectorAll(".chkdbox");
    //     console.log(chkboxes[i].dataset.index)
    //     deleteBtns = document.querySelectorAll(".deleteBtns");
    //     chkboxes[i].onchange = checkEvent;
    // }
};
showList();

var addEvent = e => {
    console.log(e);
    var str = (input.value);
    addToList(str);
    input.value = "";
}
addBtn.addEventListener('click', addEvent);

function checkEvent(e){
    console.log(e);
    let index = e.target.dataset.index;
    if(e.target.checked){
        checkedArr.push(listArr[index]);
        listArr.splice(index, 1); 
        addCheckedToLocalStorage(checkedArr);
        listHtml.innerHTML = "";
        showList();
    }else{
        console.log("unchecked!\ne:" + e);
        console.log(e);

    }
}


function addListToLocalStorage(list){
    localStorage.arr = JSON.stringify(list);
}

function addCheckedToLocalStorage(list){
    localStorage.checkedArr = JSON.stringify(list);
}

function addToList(str){
    listArr.push(str);
    addListToLocalStorage(listArr);
    listHtml.innerHTML = "";
    showList();

}



