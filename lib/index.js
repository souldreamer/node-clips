var engine = require('../build/Release/node_clips');

_assert = engine.Environment.prototype.assert;
engine.Environment.prototype.assertString = _assert; // Expose original assert, too

engine.Environment.prototype.assert = function() {
  var args = Array.prototype.slice.call(arguments, 0);
  if('[object Array]' == Object.prototype.toString.call(args[0])){
    var rule = args[0];
    var _expression;

    // This is an implied fact, e.g. (rule arg1 arg2 arg...)
    if (rule[1][0][0] === null) {
      _expression = '('+ rule[0] + ' ' + rule[1][0][1].join(' ') +')';
    } else {
      // Regular fact, e.g. (rule (arg1 val1) (arg2 val2)...)
      _expression = '(' + rule[0] + ' ';
      for(var index = 0; index < rule[1].length; index++) {
        slot = rule[1][index];
        console.dir(slot);
        if (slot[1].join) {
            _expression += '(' + slot[0] + ' ' + slot[1].join(' ') + ')';
        } else {
            _expression += '(' + slot[0] + ' ' + slot[1] + ')';
        }
      }
      _expression += ')';
    }
    args[0] = _expression;
  }
  _assert.apply(this, args);
};

module.exports = engine;
