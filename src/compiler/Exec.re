let compile: (Model.project, Rules.compilation_unit) => unit =
  (project, cunit) =>
    switch (cunit) {
    | `Create_dir(path) =>
      Logs.info(m => m("Creating dir: %s", path));
      Rules.mkdir(path);
    | `Compile(target) =>
      Logs.info(m =>
        m(
          "Compiling: %s => %s",
          target.input,
          Filename.concat(project.output_dir, target.output),
        )
      );
      Rules.compile(project.output_dir, target);
    };
