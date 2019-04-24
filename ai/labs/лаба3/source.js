var counter = 1;

function enter_task () {
        var text = $('#key').val();
        var text1 = $('#val').val();

        const lis = Array.from(document.querySelectorAll('#navbar>ul>li'));
        var Save = [];
        //alert(SattiMarks_.length);
        Array.from(document.querySelectorAll('#navbar>ul>li'),li => Save.push( Number(li.querySelector('.f').textContent ).toFixed(2)));
        //alert(JSON.stringify(Save));
        if (text !== "" && text1!== "" && !Save.includes(Number(text).toFixed(2) )) {
          //  var text = $('#key').val();
            $('#todo_list').append('<li><span class="f">' + text + ' </span>  <span class="s">' + text1 + ' </span> <input class="btn btn-secondary"  type="submit" id="edit' + counter + '" value="Edit">' + '<input class="btn btn-secondary" type="submit" class="done" id="delete' + counter + '" value="Delete">' + '</li>');
        }
$('#edit' + counter).click(function(){
    $(this).prev().attr('contenteditable','true');
    $(this).prev().focus();
});

$('#delete' + counter).click(function(){
    $(this).parent().remove();
});

  counter++;
};

$(function() {
    $('#add').on('click', enter_task);
});














