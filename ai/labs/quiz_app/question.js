function Question(text, choices, points) {
    this.text = text;
    this.choices = choices;
    this.points = points;
}

Question.prototype.isCorrectAnswer = function(choice) {
    return this.points === choice;
}
