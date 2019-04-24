function Quiz(questions) {
    this.score = 0;
    this.questions = questions;
    this.questionIndex = 0;
    this.values = [];
}

Quiz.prototype.getQuestionIndex = function() {
    return this.questions[this.questionIndex];
}

Quiz.prototype.getQuestions = function() {
	var questions = [];
	for(var i = 0; i < this.questions.length; i++) {
		questions[i] = this.questions[i].text;
	}
    return questions;
}

Quiz.prototype.guess = function(points) {
	this.score += points; 
	this.values[this.questionIndex] = (points);
	//alert(this.values[this.questionIndex]);
    this.questionIndex++;
}

Quiz.prototype.isEnded = function() {
    return this.questionIndex === this.questions.length;
}

function NewcomerQuiz(questions){
    this.score = 0;
    this.questions = questions;
    this.questionIndex = 0;
    this.values = [];
}

NewcomerQuiz.prototype = Object.create(Quiz.prototype);
NewcomerQuiz.prototype.constructor = NewcomerQuiz;

function AdvanceNewcomerQuiz(questions){
    this.score = 0;
    this.questions = questions;
    this.questionIndex = 0;
    this.values = [];
}

AdvanceNewcomerQuiz.prototype = Object.create(Quiz.prototype);
AdvanceNewcomerQuiz.prototype.constructor = AdvanceNewcomerQuiz;

function СompetentQuiz(questions){
    this.score = 0;
    this.questions = questions;
    this.questionIndex = 0;
    this.values = [];
}

СompetentQuiz.prototype = Object.create(Quiz.prototype);
СompetentQuiz.prototype.constructor = СompetentQuiz;

function ExperiencedQuiz(questions){
    this.score = 0;
    this.questions = questions;
    this.questionIndex = 0;
    this.values = [];
}

ExperiencedQuiz.prototype = Object.create(Quiz.prototype);
ExperiencedQuiz.prototype.constructor = ExperiencedQuiz;

function ExpertQuiz(questions){
    this.score = 0;
    this.questions = questions;
    this.questionIndex = 0;
    this.values = [];
}

ExpertQuiz.prototype = Object.create(Quiz.prototype);
ExpertQuiz.prototype.constructor = ExpertQuiz;

