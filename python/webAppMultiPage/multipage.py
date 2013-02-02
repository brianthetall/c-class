import webapp2

class MainPage(webapp2.RequestHandler):
  def get(self):
      self.response.headers['Content-Type'] = 'text/plain'
      self.response.write('Hello, MultiPage World!')

class SecondPage(webapp2.RequestHandler):
  def get(self):
    self.response.headers['Content-Type'] = 'text/plain'
    self.response.write('Second Page!')

app = webapp2.WSGIApplication([('/', MainPage),('/second',SecondPage)],
                              debug=True)
