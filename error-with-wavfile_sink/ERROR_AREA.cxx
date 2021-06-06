
SWIGINTERN PyObject *_wrap_wavfile_sink_sptr_make(PyObject *SWIGUNUSEDPARM(self), PyObject *args, PyObject *kwargs) {
  PyObject *resultobj = 0;
  boost::shared_ptr< gr::blocks::wavfile_sink > *arg1 = (boost::shared_ptr< gr::blocks::wavfile_sink > *) 0 ;
  char *arg2 = (char *) 0 ;
  int arg3 ;
  unsigned int arg4 ;
  int arg5 = (int) 16 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int res2 ;
  char *buf2 = 0 ;
  int alloc2 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  unsigned int val4 ;
  int ecode4 = 0 ;
  int val5 ;
  int ecode5 = 0 ;
  PyObject * obj0 = 0 ;
  PyObject * obj1 = 0 ;
  PyObject * obj2 = 0 ;
  PyObject * obj3 = 0 ;
  PyObject * obj4 = 0 ;
  char * kwnames[] = {
    (char *)"self",  (char *)"filename",  (char *)"n_channels",  (char *)"sample_rate",  (char *)"bits_per_sample",  NULL
  };
  gr::blocks::wavfile_sink::sptr result;

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOOO|O:wavfile_sink_sptr_make", kwnames, &obj0, &obj1, &obj2, &obj3, &obj4)) SWIG_fail;
  res1 = SWIG_ConvertPtr(obj0, &argp1,SWIGTYPE_p_boost__shared_ptrT_gr__blocks__wavfile_sink_t, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "wavfile_sink_sptr_make" "', argument " "1"" of type '" "boost::shared_ptr< gr::blocks::wavfile_sink > *""'");
  }
  arg1 = reinterpret_cast< boost::shared_ptr< gr::blocks::wavfile_sink > * >(argp1);
  res2 = SWIG_AsCharPtrAndSize(obj1, &buf2, NULL, &alloc2);
  if (!SWIG_IsOK(res2)) {
    SWIG_exception_fail(SWIG_ArgError(res2), "in method '" "wavfile_sink_sptr_make" "', argument " "2"" of type '" "char const *""'");
  }
  arg2 = reinterpret_cast< char * >(buf2);
  ecode3 = SWIG_AsVal_int(obj2, &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "wavfile_sink_sptr_make" "', argument " "3"" of type '" "int""'");
  }
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_unsigned_SS_int(obj3, &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "wavfile_sink_sptr_make" "', argument " "4"" of type '" "unsigned int""'");
  }
  arg4 = static_cast< unsigned int >(val4);
  if (obj4) {
    ecode5 = SWIG_AsVal_int(obj4, &val5);
    if (!SWIG_IsOK(ecode5)) {
      SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "wavfile_sink_sptr_make" "', argument " "5"" of type '" "int""'");
    }
    arg5 = static_cast< int >(val5);
  }
  {
    try {
      result = (*arg1)->make((char const *)arg2,arg3,arg4,arg5);
    }
    catch(std::exception &e) {
      SWIG_exception(SWIG_RuntimeError, e.what());
    }
    catch(...) {
      SWIG_exception(SWIG_RuntimeError, "Unknown exception");
    }

  }
  resultobj = SWIG_NewPointerObj((new gr::blocks::wavfile_sink::sptr(static_cast< const gr::blocks::wavfile_sink::sptr& >(result))), SWIGTYPE_p_boost__shared_ptrT_gr__blocks__wavfile_sink_t, SWIG_POINTER_OWN |  0 );
  if (alloc2 == SWIG_NEWOBJ) delete[] buf2;
  return resultobj;
fail:
  if (alloc2 == SWIG_NEWOBJ) delete[] buf2;
  return NULL;
}


SWIGINTERN PyObject *_wrap_wavfile_sink_sptr_open(PyObject *SWIGUNUSEDPARM(self), PyObject *args, PyObject *kwargs) {
  PyObject *resultobj = 0;
  boost::shared_ptr< gr::blocks::wavfile_sink > *arg1 = (boost::shared_ptr< gr::blocks::wavfile_sink > *) 0 ;
  char *arg2 = (char *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int res2 ;
  char *buf2 = 0 ;
  int alloc2 = 0 ;
  PyObject * obj0 = 0 ;
  PyObject * obj1 = 0 ;
  char * kwnames[] = {
    (char *)"self",  (char *)"filename",  NULL
  };
  bool result;

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO:wavfile_sink_sptr_open", kwnames, &obj0, &obj1)) SWIG_fail;
  res1 = SWIG_ConvertPtr(obj0, &argp1,SWIGTYPE_p_boost__shared_ptrT_gr__blocks__wavfile_sink_t, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "wavfile_sink_sptr_open" "', argument " "1"" of type '" "boost::shared_ptr< gr::blocks::wavfile_sink > *""'");
  }
  arg1 = reinterpret_cast< boost::shared_ptr< gr::blocks::wavfile_sink > * >(argp1);
  res2 = SWIG_AsCharPtrAndSize(obj1, &buf2, NULL, &alloc2);
  if (!SWIG_IsOK(res2)) {
    SWIG_exception_fail(SWIG_ArgError(res2), "in method '" "wavfile_sink_sptr_open" "', argument " "2"" of type '" "char const *""'");
  }
  arg2 = reinterpret_cast< char * >(buf2);
  {
    try {
      result = (bool)(*arg1)->open((char const *)arg2);
    }
    catch(std::exception &e) {
      SWIG_exception(SWIG_RuntimeError, e.what());
    }
    catch(...) {
      SWIG_exception(SWIG_RuntimeError, "Unknown exception");
    }

  }
  resultobj = SWIG_From_bool(static_cast< bool >(result));
  if (alloc2 == SWIG_NEWOBJ) delete[] buf2;
  return resultobj;
fail:
  if (alloc2 == SWIG_NEWOBJ) delete[] buf2;
  return NULL;
}


SWIGINTERN PyObject *_wrap_wavfile_sink_sptr_close(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  PyObject *resultobj = 0;
  boost::shared_ptr< gr::blocks::wavfile_sink > *arg1 = (boost::shared_ptr< gr::blocks::wavfile_sink > *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;

  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_boost__shared_ptrT_gr__blocks__wavfile_sink_t, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "wavfile_sink_sptr_close" "', argument " "1"" of type '" "boost::shared_ptr< gr::blocks::wavfile_sink > *""'"); 
