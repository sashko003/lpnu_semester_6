function populate(quiz) {
    //alert(quiz);
    //alert("populate func");
    if(quiz.isEnded()) {
        showScores(quiz);
    }
    else {
        // show question
        var element = document.getElementById("question");
        element.innerHTML = quiz.getQuestionIndex().text;

        // show options
        var choices = quiz.getQuestionIndex().choices;
        for(var i = 0; i < choices.length; i++) {
            var element = document.getElementById("choice" + i);
            element.innerHTML = choices[i][0];
            guess("btn" + i, choices[i][1], quiz);
        }

        showProgress(quiz);
    }
};

function guess(id, guess, quiz) {
    //alert("guess func");
    var button = document.getElementById(id);
    button.onclick = function() {
        quiz.guess(guess);
        populate(quiz);
    }
};


function showProgress(quiz) {
    var currentQuestionNumber = quiz.questionIndex + 1;
    var element = document.getElementById("progress");
    element.innerHTML = "Question " + currentQuestionNumber + " of " + quiz.questions.length;
};

function showScores(quiz) {
    //alert("showScores func");
    var scoreHTML = "<h1>Result</h1>";
    scoreHTML += "<h2 id='score'> Your scores: " + quiz.score + "</h2>";
    scoreHTML += "<div id = 'diagram' class='diagram'></div>";
    if(mainI < mainQuiz.length-1)
    {
        scoreHTML += "<input type='button' id='next_btn' value='Next quiz' class='next_btn'/>";
    }
    else
    {
        scoreHTML += "<input type='button' id='res_btn' value='Result' class='next_btn'/>"; 
    }
    
    var element = document.getElementById("quiz");
    element.innerHTML = scoreHTML;
    var data = [{
              x: quiz.getQuestions(),
              y: quiz.values,
              type: 'bar'
            }];

    Plotly.newPlot('diagram', data, {}, {showSendToCloud:true});
    
    if(mainI < mainQuiz.length-1)
    {
        alert(mainI);
        var button = document.getElementById('next_btn');
    
    
        button.onclick = function() {
            //alert("next btn");
            var html = '<h1>Quiz</h1>'; 
            html += '<hr style="margin-bottom: 20px">';

            html +='<p id="question"></p>';

            var buttons ='<button id="btn0"><span id="choice0"></span></button><br>';
            buttons +=' <button id="btn1"><span id="choice1"></span></button><br>';
            buttons +=' <button id="btn2"><span id="choice2"></span></button><br>';
            html +='<div class="buttons">'+buttons+'</div>';

            html +=' <hr style="margin-top: 20px">';
            html +=' <footer><p id="progress">Question x of y</p></footer>';
            var element = document.getElementById("quiz");
            element.innerHTML = html;
            mainI++;
            populate(mainQuiz[mainI]);
        }
    }
    else
    {
        var button = document.getElementById('res_btn');
        button.onclick = function() {
            alert("res btn");
            var gameOverHTML = '<h1>Result</h1>';
            var mainScore = 0;
            var arr_str = ['Newcomer', 'AdvanceNewcomer', 'Competent', 'Experienced', 'Proficient'];
            var arr_val = [];
            for(var i = 0; i<mainQuiz.length; ++i){
                mainScore += mainQuiz[i].score;
                arr_val[i] = mainQuiz[i].score;
            }
            alert(arr_val);
            gameOverHTML += "<h2 id='score'> Your scores: " + mainScore + "</h2>";
            gameOverHTML += "<div id = 'diagram' class='diagram'></div>";
            var element = document.getElementById("quiz");
            element.innerHTML = gameOverHTML;
            var data = [{
              labels: arr_str,
              values: arr_val,
              type: 'pie',
            }];
            var layout = {
              height: 400,
              width: 500
            };

            Plotly.newPlot('diagram', data, layout);
        }
    }
};

// create questions
var questionsNCQ = [
    new Question("Переживаєте за успіх в роботі?",
        [
          ["сильно", 5], 
          ["не дуже", 3], 
          ["спокійний", 2]
        ]),
    new Question("Як швидко прагнете досягти результату?", 
        [
         ["поступово", 2], 
         ["якомога швидше", 3], 
         ["дуже швидко", 5]
        ]), 
    new Question("Легко попадаєте в тупик при проблемах в роботі?", 
        [
         ["неодмінно", 5], 
         ["поступово", 3],
         ["зрідка", 2], 
        ]),
    new Question("Чи потрібен чіткий алгоритм для вирішення задач?", 
        [
         ["так", 5],
         ["в окремих випадках", 3],
         ["не потрібен", 2],
        ]),
];

var questionsAVNQ = [
    new Question("Чи використовуєте власний досвід при вирішенні задач?",
        [
          ["зрідка", 5], 
          ["частково", 3], 
          ["ні", 2]
        ]),
    new Question("Чи користуєтесь фіксованими правилами  для вирішення задач?", 
        [
         ["так", 2], 
         ["в окремих випадках", 3], 
         ["не потрібні", 5]
        ]), 
    new Question("Чи відчуваєте ви загальний контекст вирішення задачі?", 
        [
         ["так", 5], 
         ["частково", 3],
         ["в окремих випадках", 2], 
        ]),
    ];

var questionsCMTQ = [
    new Question("Чи вистачає вам ініціативи при вирішенні задач?",
        [
          ["так", 5], 
          ["зрідка", 3], 
          ["потрібне натхнення", 2]
        ]),
    new Question("Чи можете вирішувати проблеми, з якими ще не стикались?", 
        [
         ["так", 2], 
         ["в окремих випадках", 3], 
         ["ні", 5]
        ]), 
    new Question("Чи можете ви побудувати модель вирішуваної задачі?", 
        [
         ["так", 5], 
         ["не повністю", 3],
         ["в окремих випадках", 2], 
        ]),
    ];

var questionsPROQ = [
    new Question("Чи  необхідний вам весь контекст задачі?",
        [
          ["так", 5], 
          ["в окремих деталях", 3], 
          ["в загальному", 2]
        ]),
    new Question("Чи переглядаєте ви свої наміри до вирішення задачі?", 
        [
         ["так", 5], 
         ["зрідка", 3], 
         ["коли є потреба", 2]
        ]), 
    new Question("Чи можете ви побудувати модель вирішуваної задачі?", 
        [
         ["так", 5], 
         ["зрідка", 3], 
         ["коли є потреба", 2] 
        ]),
    ];

var questionsEXQ = [
    new Question("Чи обираєте ви нові методи своєї роботи?",
        [
          ["так", 5], 
          ["вибірково", 3], 
          ["вистачає досвіду", 2]
        ]),
    new Question("Чи допомагає власна інтуїція при вирішенні задач?", 
        [
         ["так", 5], 
         ["частково", 3], 
         ["при емоційному напруженні", 2]
        ]), 
    new Question("Чи застовуєте рішення задач за аналогією?", 
        [
         ["часто", 5], 
         ["зрідка", 3], 
         ["тільки власний варіант", 2] 
        ]),
    ];

// create quiz
var mainQuiz = [new NewcomerQuiz(questionsNCQ),
            new AdvanceNewcomerQuiz(questionsAVNQ),
            new СompetentQuiz(questionsCMTQ),
            new ExperiencedQuiz(questionsPROQ),
            new ExpertQuiz(questionsEXQ)];

var mainI = 0;
populate(mainQuiz[mainI]);






