module.exports = {
  build: {
    options: {
      config: 'config.rb',
      bundleExec: true
    }
  },
  prod:{
    options: {
      config: 'config.rb',
      bundleExec: true,
      force: true,
      //environment: 'production',
      outputStyle: 'compressed',
      noLineComments: true
    }
  }
};