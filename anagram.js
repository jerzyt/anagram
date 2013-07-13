
function sortChars(word) {
	var charArr = word.split('');
	var key = charArr.sort().join('');
	return key;
}

var fileName = 'words';
var fs = require('fs');
fs.readFile(fileName, 'utf8', function(err, data) {
	if(!err) {
		var anagramHash = {};
		var wordArr = data.toString().split('\n');
		for(var i in wordArr) {
			var word = wordArr[i];
			if(word) {
				key = sortChars(word);
				if((key in anagramHash) == false) {
					anagramHash[key] = [];
				}
				anagramHash[key].push(word);
			}
		}
		for(var x in anagramHash) {
			if(x) {
				var a = anagramHash[x];
				if(a.length > 3) {
					console.log(x + '\t=>\t' + a.join(', '));
				}
			}
		}
	} else {
		throw err;
	}
});
