const helper = require('./helpers')
const fs = require('fs')

args = process.argv
function parseCmdArgs(args) {
    const [nodePath, fileName, cmd, ...options] = args
    parsedOptions = options.reduce((cumulativeData, element) => {
        // ex: title="great todo" body="great stuff todo" => [title: "great todo"]
        const [optionName, optionValue] = element.split('=');
        cumulativeData[optionName] = optionValue;
        return cumulativeData;
    }, {})
    parsedOptions.cmd = cmd;
    return {
        parsedOptions,
    }

}

function main(cmdArgs) {
    todo_list = helper.load_todo()

    const parsedOptions = parseCmdArgs(cmdArgs).parsedOptions;
    switch (parsedOptions.cmd) {
        case 'add':
            helper.add(parsedOptions, todo_list)
            break;

        case 'edit':
            helper.edit(parsedOptions, todo_list)
            break;

        case 'list':
            helper.list(todo_list)
            break;

        case 'remove':
            helper.remove(parsedOptions, todo_list)
            break;

        case 'check':
            helper.check(parsedOptions, todo_list)
            break;

        case 'uncheck':
            helper.uncheck(parsedOptions, todo_list)
            break;

        default:
            break;
    }
}

main(process.argv)