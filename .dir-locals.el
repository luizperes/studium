;; cmake-ide bindings.
;; Note that this is not really your conventional bindings, though.
;; We need to eval a working-dir variable and then manually set the
;; CMake directories manually.
((nil .
      ((eval . (setq working-dir
                     (file-name-directory
                      (let ((d (dir-locals-find-file ".")))
                        (if (stringp d)
                            d
                          (car d))))))
       (eval . (setq cmake-ide-project-dir working-dir))
       (eval . (setq cmake-ide-build-dir (concat working-dir "build"))))))
