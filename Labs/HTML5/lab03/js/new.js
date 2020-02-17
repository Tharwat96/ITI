class TaskList{
    uncheckedArr = new Array;
    checkedArr = new Array;
    constructor(){}
    addTask(task){
        if(!task.checked){
            this.uncheckedArr.push(task.text);
        }
        else if (task.checked){
            this.checkedArr.push(task.text);
        }
    }

    pushToUncheckedList(task){
        this.uncheckedArr.push(task);
    }
    removeFromUncheckedList(id){
        let task=this.uncheckedArr[id];
        this.uncheckedArr.splice(id,1);
        return task;
    }
    pushToCheckedList(task){
        this.checkedArr.push(task);
    }
    removeFromCheckedList(id){
        let task=this.checkedArr[id];
        this.checkedArr.splice(id,1);
        return task;
    }

}
class Task{
    id;
    checked = false;
    checkbox = document.createElement('input');
    delBtn = document.createElement('button');
    constructor(text){
        this.text = text;
        this.checkbox.type='checkbox';
    }

    setId(id){
        this.id = id;
    }

    setChecked(status){
        this.checked = status;
    }



}

var textInput = document.querySelector('#new-task');
var addBtn = document.querySelector('#add-task');
var listHtml = document.querySelector('#tdl-list');
var ol = document.createElement('ol');
listHtml.appendChild(ol);

taskList = new TaskList;

addBtn.addEventListener('click', e=>{
    console.log("add button presssed!");
    task = new Task(textInput);
    taskList.pushToUncheckedList(task);
    textInput.value = "";
    
})
