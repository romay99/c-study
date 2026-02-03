import CodeRunner from '../components/CodeRunner'
import { runnableExamples } from '../content/codeData'

const defaultCode = `#include <stdio.h>

int main() {
    printf("Hello, C!\\n");
    return 0;
}`

export default function Playground() {
  return (
    <div className="page-playground">
      <header className="page-header">
        <h1>실행해보기</h1>
        <p>C 코드를 작성하고 브라우저에서 실행합니다. Piston API를 사용하며 인터넷 연결이 필요합니다.</p>
      </header>

      <section className="section">
        <h2>빈 캔버스</h2>
        <CodeRunner defaultCode={defaultCode} label="실행" />
      </section>

      <section className="section">
        <h2>예제 선택</h2>
        <p className="muted">아래 예제를 불러와서 수정·실행할 수 있습니다.</p>
        <div className="example-grid">
          {Object.entries(runnableExamples).map(([key, code]) => (
            <details key={key} className="example-item">
              <summary>{key.replace(/_/g, ' ')}</summary>
              <CodeRunner defaultCode={code} label="이 예제 실행" />
            </details>
          ))}
        </div>
      </section>
    </div>
  )
}
