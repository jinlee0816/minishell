#include "minishell.h"

// 파이프 (|) 처리
void do_pipe(char **tokens, int pipe_idx[MAX_TOKEN], int pipe_cnt)
{
  int pipe_fd[MAX_TOKEN][2] = {0, };
  int pid;
  int status;

  pipe(pipe_fd[0]);
  if ((pid = fork()) < 0) {
    fprintf(stderr, "fork error!\n");
    exit(1);
  }
  if (pid == 0) {
    dup2(pipe_fd[0][1], STDOUT_FILENO);
    execvp(tokens[pipe_idx[0]], &tokens[pipe_idx[0]]);
    fprintf(stderr, "execvp error!\n");
  }
  close(pipe_fd[0][1]);
  wait(&status);
  if (WIFSIGNALED(status) || WIFSTOPPED(status))
    exit(1);

  for (int i = 0; i < pipe_cnt - 1; i++) {
    pipe(pipe_fd[i+1]);
    if ((pid = fork()) < 0) {
      fprintf(stderr, "fork error!\n");
      exit(1);
    }
    else if (pid == 0) {
      dup2(pipe_fd[i][0], STDIN_FILENO);
      dup2(pipe_fd[i+1][1], STDOUT_FILENO);
      execvp(tokens[pipe_idx[i+1]], &tokens[pipe_idx[i+1]]);
      fprintf(stderr, "execvp error!\n");
    }
    close(pipe_fd[i+1][1]);
    wait(&status);
    if (WIFSIGNALED(status) || WIFSTOPPED(status))
      exit(1);
  }

  if ((pid = fork()) < 0) {
    fprintf(stderr, "fork error!\n");
    exit(1);
  }
  else if (pid == 0) {
    dup2(pipe_fd[pipe_cnt-1][0], STDIN_FILENO);
    execvp(tokens[pipe_idx[pipe_cnt]], &tokens[pipe_idx[pipe_cnt]]);
  }
  wait(&status);
  if (WIFSIGNALED(status) || WIFSTOPPED(status))
    exit(1);
  return;
}

// 명령어 실행
void run_commands(char **tokens)
{
  bool has_pipe = false;
  int pipe_cnt = 0;
  int pipe_idx[MAX_TOKEN] = {0, };
  for (int i = 0; tokens[i]; i++) {
    if (!strcmp(tokens[i], "|")) {
      tokens[i] = NULL;
      pipe_idx[++pipe_cnt] = i+1;
      has_pipe = true;
    }
  }
  if (has_pipe) {
    do_pipe(tokens, pipe_idx, pipe_cnt);
  }
  else {
    if (execvp(tokens[0], tokens) < 0) {
      if (errno == 2) {
        fprintf(stderr, "command not found!\n");
        exit(1);
      }
      else {
        fprintf(stderr, "execvp error!\n");
        exit(1);
      }
    }
    int status;
    wait(&status);
    if (WIFSIGNALED(status) || WIFSTOPPED(status)) {
      exit(1);
    }
  }
  exit(0);
}

int main(int argc, char* argv[])
{
  char  line[MAX_INPUT_SIZE];           
  char  **tokens;             
  int i;
  FILE* fp;

  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  print_minishell();
  while (1) {
    bzero(line, sizeof(line));
    printf("jinwooklee$ ");
    scanf("%[^\n]", line);
    getchar();
    
    line[strlen(line)] = '\0';
    tokens = ft_split(line, " \n\t\0");
    if (!tokens[0])
      continue;
    if(!strcmp(tokens[0], "exit"))
      exit(1);
    if(!strcmp(tokens[0], "cd"))
    {
      cmd_cd(argc, tokens);
      continue;
    }
    int pid;
    if ((pid = fork()) < 0) {
      fprintf(stderr, "fork error!\n");
      exit(1);
    }
    else if (pid == 0)
      run_commands(tokens);
    else {
      int status;
      waitpid(pid, &status, 0);
      if (WIFSIGNALED(status) || WIFSTOPPED(status) || WEXITSTATUS(status) == 1)
        fprintf(stderr, "incorrect command!\n");
      for (i=0;tokens[i]!=NULL;i++)
        free(tokens[i]);
      free(tokens);
    }
  }
  return 0;
}