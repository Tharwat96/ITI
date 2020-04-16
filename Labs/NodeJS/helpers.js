const fs = require('fs')
const util = require('util')
module.exports = {

    load_todo: function () {
        todo_list = []
        path = './todo_list.json'
        try {
            if (fs.existsSync(path)) {
                //file exists
                todo_list = this.read_json_file('todo_list');
            }

        }
        catch (err) {
            console.log(err)
            todo_list = []
        }
        return todo_list
    },

    add: function (args, todo_list) {
        (todo_list.length == 0) ? id = 1 : id = todo_list[todo_list.length - 1].id + 1;
        todo = {
            id: id,
            title: args.title,
            body: args.body,
            checked: false,
        }
        todo_list.push(todo)
        this.write_json_file(todo_list, 'todo_list.json')
        console.log(`A new todo added successfully under id #${id}`)
    },

    edit: function (args, todo_list) {
        if (args.hasOwnProperty('id')) {
            id = args.id;
            isFound = false;
            todo_list = todo_list.map((todo, index) => {
                if (todo.id == id) {
                    isFound = true;
                    if (args.hasOwnProperty('title')) {
                        todo.title = args.title;
                        console.log("title changed successfully.");
                    }
                    else console.log("title not changed, no 'title=' parameter found.")
                    if (args.hasOwnProperty('body'))
                        todo.body = args.body
                    else console.log("body not changed, no 'body=' parameter found.")
                }
                return todo
            })
            if (!isFound) console.log(`todo #${id} was not found`)
            this.write_json_file(todo_list, 'todo_list.json')
        }
        else console.log("No id input found, please add your desired id in the format 'id=<num>' where <num> is your desired id")
    },

    remove: function (args, list) {
        if (args.hasOwnProperty('id')) {
            id = args.id;
            isFound = false;
            todo_list = list.filter((todo) => {
                if (todo.id == id)
                    isFound = true;
                if (todo.id != id) {

                    return todo
                }
            })
            if (isFound) console.log(`todo #${id} removed successfully`)
            else console.log(`todo #${id} was not found`)
            this.write_json_file(todo_list, 'todo_list.json')
        }
        else console.log("No id input found, please add your desired id in the format 'id=<num>' where <num> is your desired id")
    },
    list: function (todo_list) {
        for (todo in todo_list) {
            console.log(`ID: ${todo_list[todo].id} | title: ${todo_list[todo].title} | body: ${todo_list[todo].body} | checked: ${todo_list[todo].checked}`)
        }
    },
    check: function (args, todo_list) {
        if (args.hasOwnProperty('id')) {
            id = args.id;
            isFound = false;
            todo_list = todo_list.map((todo, index) => {

                if (todo.id == id) {
                    if (todo.checked == false) {
                        todo.checked = true
                        console.log(`todo #${id} checked successfully`)
                    }
                    else if (todo.checked == true) console.log(`todo #${id} is already checked`);
                    isFound = true;
                }
                return todo
            })
            this.write_json_file(todo_list, 'todo_list.json')
            if (!isFound) console.log(`todo #${id} was not found`)
        }
        else console.log("No id input found, please add your desired id in the format 'id=<num>' where <num> is your desired id")
    },
    uncheck: function (args) {
        if (args.hasOwnProperty('id')) {
            id = args.id;
            isFound = false;
            todo_list = todo_list.map((todo, index) => {
                if (todo.id == id) {
                    if (todo.checked == true) {
                        todo.checked = false;
                        console.log(`todo #${id} unchecked successfully`)
                    }
                    else if (todo.checked == false) console.log(`todo #${id} is already unchecked`);
                    isFound = true;
                }
                return todo
            })
            this.write_json_file(todo_list, 'todo_list.json')
            if (!isFound) console.log(`todo #${id} was not found`)
        }
        else console.log("No id input found, please add your desired id in the format 'id=<num>' where <num> is your desired id")
    },

    write_json_file: function (data, fileName) {
        jsonContent = JSON.stringify(data)
        fs.writeFileSync(fileName, jsonContent)
    },

    read_json_file: function (fileName) {
        var jsonParsed = []
        jsonParsed = JSON.parse(fs.readFileSync(`${fileName}.json`, 'utf8'));
        return jsonParsed
    },

    log_object: function (object) {
        console.log(util.inspect(object, false, null, true /* enable colors */))
    }

}