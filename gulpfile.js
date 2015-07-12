var gulp        = require('gulp'),
    compass     = require('gulp-compass');


gulp.task('compass', function() {
  gulp.src('sass/*.scss')
    .pipe(compass({
      config_file: 'config.rb',
      css: 'css',
      sass: 'sass',
      bundle_exec: true
    }))
    .pipe(gulp.dest('css'));
});

// This defines the default task, which is the task or tasks run when you enter `gulp` alone on the command line.
gulp.task('default', ['compass']);