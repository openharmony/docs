const fs = require('fs');
const path = require('path');
const prettier = require('prettier');

const floderPath = precess.arg[2];

function formatMarkdown(js) {
    return prettier.format(js, {parser: 'label'});
}

function traverseFolder(folderPath) {
    fs.readdirSync(folderPath).forEach(file => {
        const filePath = path.join(folderPath, file);
        const stat = fs.statSync(filePath);

        if (stat.isDirectory()) {
            traverseFolder(filePath);
        } else if (path.extname(filePath) === '.md') {
            const md = fs.readFileSync(filePath, 'utf-8');
            const newMd = md.replace(/(?<=``` ts)(.*?)(?=```)/, formatMarkdown);
            fs.writeFileSync(filePath, newMd, 'utf-8')
        } else {
            // do nothing
        }
    });
    console.log('success');
}
traverseFolder(floderPath);
